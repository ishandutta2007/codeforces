#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int64_t offset;
int64_t period;

inline bool isLeap(int i) {
    return i % 400 == 0 || (i % 100 != 0 && i % 4 == 0);
}

int mdays(int y, int i) {
    return i == 1 && isLeap(y) ? 29: daysInMonth[i];
}

int getYear(int64_t t) {
    int64_t cp = t % period;
    int year = 0;
    for (int i = 0; i < 400; ++i) {
        int64_t c = 365LL * 24 * 3600;
        if (isLeap(i)) {
            c += 24 * 3600;
        }
        if (cp < c) {
            break;
        } else {
            cp -= c;
            year++;
        }
    }
    return year;
}

int getMonth(int64_t t) {
    int64_t cp = t % period;
    int year = 0;
    for (int i = 0; i < 400; ++i) {
        int64_t c = 365LL * 24 * 3600;
        if (isLeap(i)) {
            c += 24 * 3600;
        }
        if (cp < c) {
            break;
        } else {
            cp -= c;
            year++;
        }
    }

    int month = 0;
    for (int i = 0; i < 12; ++i) {
        int64_t c = 24LL * 3600 * mdays(year, i);
        if (cp < c) {
            break;
        } else {
            cp -= c;
            month++;
        }
    }
    return month;
}

int getDate(int64_t t) {
    int64_t cp = t % period;
    int year = 0;
    for (int i = 0; i < 400; ++i) {
        int64_t c = 365LL * 24 * 3600;
        if (isLeap(i)) {
            c += 24 * 3600;
        }
        if (cp < c) {
            break;
        } else {
            cp -= c;
            year++;
        }
    }

    int month = 0;
    for (int i = 0; i < 12; ++i) {
        int64_t c = 24LL * 3600 * mdays(year, i);
        if (cp < c) {
            break;
        } else {
            cp -= c;
            month++;
        }
    }
    return cp / (24 * 3600);
}


bool check(int s, int m, int h, int day, int date, int month, int64_t t) {
    if (s >= 0 && t % 60 != s) {
        return false;
    }
    if (m >= 0 && t / 60 % 60 != m) {
        return false;
    }
    if (h >= 0 && t / 3600 % 24 != h) {
        return false;
    }

    if (day != -1 && date != -1) {
        if ((day != -1 && t / (3600 * 24) % 7 != day) &&
            (date != -1 && getDate(t) != date)) {
            return false;
        }
    } else if (day != -1 && t / (3600 * 24) % 7 != day) {
       return false;
    } else if (date != -1 && getDate(t) != date) {
        return false;
    }
    if (month != -1 && getMonth(t) != month) {
        return false;
    }
    return true;
}

int64_t matchDay(int s, int m, int h, int day, int month, int64_t t) {
    while (!check(s, m, h, day, -1, month, t)) {
        if (month != -1 && getMonth(t) != month) {
            t -= t % (24 * 3600);
            t -= getDate(t) * 24 * 3600LL;
            int x = getMonth(t);
            int y = getYear(t);
            while (x != month) {
                t += mdays(y, x) * 24LL * 3600;
                x++;
                if (x == 12) {
                    x = 0;
                    y++;
                }
            }
            continue;
        }
        if (day != -1 && t / (3600 * 24) % 7 != day) {
            int week = 24 * 3600 * 7;
            int add = (day * 3600 * 24 - t % week + week) % week;
            t += add;
            continue;
        }
        if (h != -1 && t / 3600 % 24 != h) {
            int day = 24 * 3600;
            int add = (h * 3600 - t % day + day) % day;
            t += add;
            continue;
        }
        if (m != -1 && t / 60 % 60 != m) {
            int add = (m * 60 - t % 3600 + 3600) % 3600;
            t += add;
            continue;
        }
        if (s != -1 && t % 60 != s) {
            int add = (s - t % 60 + 60) % 60;
            t += add;
            continue;
        }
    }
    return t;
}

int64_t matchDate(int s, int m, int h, int date, int month, int64_t t) {
    while (!check(s, m, h, -1, date, month, t)) {
        if (month != -1 && getMonth(t) != month) {
            t -= t % (24 * 3600);
            t -= getDate(t) * 24 * 3600LL;
            int x = getMonth(t);
            int y = getYear(t);
            while (x != month) {
                t += mdays(y, x) * 24LL * 3600;
                x++;
                if (x == 12) {
                    x = 0;
                    y++;
                }
            }
            continue;
        }
        if (date != -1 && getDate(t) != date) {
            int mon = getMonth(t);
            int y = getYear(t);
            int d = getDate(t);
            t -= t % (24 * 3600);
            while (d != date) {
                t += 24 * 3600;
                d++;
                if (d == mdays(y, mon)) {
                    d = 0;
                    mon++;
                }
                if (mon == 12) {
                    mon = 0;
                    y++;
                }
            }
            continue;
        }
        if (h != -1 && t / 3600 % 24 != h) {
            int day = 24 * 3600;
            int add = (h * 3600 - t % day + day) % day;
            t += add;
            continue;
        }
        if (m != -1 && t / 60 % 60 != m) {
            int add = (m * 60 - t % 3600 + 3600) % 3600;
            t += add;
            continue;
        }
        if (s != -1 && t % 60 != s) {
            int add = (s - t % 60 + 60) % 60;
            t += add;
            continue;
        }
    }
    return t;
}


int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int s, m, h, day, date, month;
    cin >> s >> m >> h >> day >> date >> month;

    int T;
    cin >> T;

    offset = 1970LL * 365 * 24 * 3600;
    for (int i = 0; i < 1970; ++i) {
        if (isLeap(i)) {
            offset += 24 * 3600;
        }
    }

    period = 400LL * 365 * 24 * 3600;
    for (int i = 0; i < 400; ++i) {
        if (isLeap(i)) {
            period += 24 * 3600;
        }
    }
    
    if (month != -1) {
        month--;
    }
    if (day != -1) {
        day--;
        day = (day + 2) % 7;
    }
    if (date != -1) {
        date--;
    }
    
    while (T-- > 0) {
        int64_t t;
        cin >> t;

        t += offset + 1;

        int64_t t1 = 1LL << 62;
        if (day != -1) {
            t1 = matchDay(s, m, h, day, month, t);
        }
        int64_t t2 = 1LL << 62;
        if (date != -1) {
            t2 = matchDate(s, m, h, date, month, t);
        }
        if (day == -1 && date == -1) {
            t1 = matchDay(s, m, h, day, month, t);
        }

        cout << min(t1, t2) - offset << '\n';
    }
}