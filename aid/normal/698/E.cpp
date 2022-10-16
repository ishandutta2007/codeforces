#include <iostream>

using namespace std;

inline int getSecsInYear(int year) {
    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        return 60 * 60 * 24 * 366;
    else
        return 60 * 60 * 24 * 365;
}

int lm[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int getSecsInMonth(int year, int month) {
    if(month == 1) {
        if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
            return 60 * 60 * 24 * 29;
        else
            return 60 * 60 * 24 * 28;
    }
    else
        return 60 * 60 * 24 * lm[month];
}

inline void incrementDay(int &day, int &date, int &month, int &year, long long &t) {
    day = (day + 1) % 7;
    t += 60 * 60 * 24;
    if(month == 1) {
        if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
            if(date == 28) {
                date = 0;
                month++;
            }
            else
                date++;
        }
        else {
            if(date == 27) {
                date = 0;
                month++;
            }
            else
                date++;
        }
    }
    else {
        if(date + 1 == lm[month]) {
            date = 0;
            if(month == 11) {
                month = 0;
                year++;
            }
            else
                month++;
        }
        else
            date++;
    }
}

inline bool incrementTime(int &s, int &m, int &h, long long &t) {
    t++;
    if(s == 59) {
        s = 0;
        if(m == 59) {
            m = 0;
            if(h == 23)
                return false;
            else
                h++;
        }
        else
            m++;
    }
    else
        s++;
    return true;
}

inline bool check(int x, int y) {
    if(y == -1)
        return true;
    return x == y;
}

inline bool checkDay(int cday, int cdate, int day, int date) {
    if(day == -1)
        return check(cdate, date);
    if(date == -1)
        return check(cday, day);
    return check(cdate, date) || check(cday, day);
}

inline long long solveToday(int cs, int cm, int ch,
                            int cday, int cdate, int cmonth, int cyear, long long ct,
                            int s, int m, int h, int day, int date, int month) {
    if(!checkDay(cday, cdate, day, date) || !check(cmonth, month))
        return -1;
    while(true) {
        if(check(cs, s) && check(cm, m) && check(ch, h))
            return ct;
        if(!incrementTime(cs, cm, ch, ct))
            break;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int s, m, h, day, date, month;
    cin >> s >> m >> h >> day >> date >> month;
    if(day != -1)
        day--;
    if(date != -1)
        date--;
    if(month != -1)
        month--;
    int n;
    cin >> n;
    for(int q = 0; q < n; q++) {
        long long t;
        cin >> t;
        t++;
        int cs = 0, cm = 0, ch = 0, cday = 3, cdate = 0, cmonth = 0, cyear = 1970;
        long long ct = t;
        while(true) {
            int sy = getSecsInYear(cyear);
            if(t >= sy) {
                t -= sy;
                cday = (cday + sy / (60 * 60 * 24)) % 7;
                cyear++;
            }
            else
                break;
        }
        while(true) {
            int sm = getSecsInMonth(cyear, cmonth);
            if(t >= sm) {
                t -= sm;
                cday = (cday + sm / (60 * 60 * 24)) % 7;
                cmonth++;
            }
            else
                break;
        }
        while(t >= 60 * 60 * 24) {
            t -= 60 * 60 * 24;
            cday = (cday + 1) % 7;
            cdate++;
        }
        while(t >= 60 * 60) {
            t -= 60 * 60;
            ch++;
        }
        while(t >= 60) {
            t -= 60;
            cm++;
        }
        cs += t;
        long long ans = solveToday(cs, cm, ch, cday, cdate, cmonth, cyear, ct,
                                   s, m, h, day, date, month);
        if(ans != -1) {
            cout << ans << '\n';
            continue;
        }
        ct -= cs + 60 * cm + 60 * 60 * ch;
        while(true) {
            incrementDay(cday, cdate, cmonth, cyear, ct);
            ans = solveToday(0, 0, 0, cday, cdate, cmonth, cyear, ct,
                             s, m, h, day, date, month);
            if(ans != -1)
                break;
        }
        cout << ans << '\n';
    }
    return 0;
}