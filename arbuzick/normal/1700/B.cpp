#include <bits/stdc++.h>

using namespace std;

struct Integer {
   private:
    vector<int> number;
    bool negative;

   public:
    Integer() {
        negative = false;
    }
    Integer(string _number) {
        reverse(_number.begin(), _number.end());
        if (_number.back() == '-') {
            negative = true;
            _number.pop_back();
        } else {
            negative = false;
        }
        for (int i = 0; i < (int)_number.size(); ++i) {
            number.push_back(_number[i] - '0');
        }
    }
    Integer(vector<int> _number, bool _negative) {
        number = _number;
        negative = _negative;
    }
    int getDigit(int pos) const {
        if (pos < number.size()) {
            return number[pos];
        }
        return 0;
    }
    bool operator==(Integer b) const {
        return number == b.number && negative == b.negative;
    }
    bool operator!=(Integer b) const {
        return !(*this == b);
    }
    bool operator<(Integer b) const {
        if (negative != b.negative) {
            return negative;
        }
        for (int i = (int)max(number.size(), b.number.size()) - 1; i >= 0; --i) {
            if (getDigit(i) != b.getDigit(i)) {
                if (negative) {
                    return getDigit(i) > b.getDigit(i);
                }
                return getDigit(i) < b.getDigit(i);
            }
        }
        return false;
    }
    bool operator>(Integer b) const {
        return (*this != b) && !(*this < b);
    }
    bool operator<=(Integer b) const {
        return (*this < b) || (*this == b);
    }
    bool operator>=(Integer b) const {
        return (*this > b) || (*this == b);
    }
    Integer operator-() const {
        return Integer(number, !negative);
    }
    Integer getAbs() const {
        if (negative) {
            return -(*this);
        }
        return *this;
    }
    Integer operator+(Integer b) const {
        if (negative != b.negative) {
            if (getAbs() < b.getAbs()) {
                return b + (*this);
            }
            Integer ans;
            ans.negative = negative;
            int taken = 0;
            for (int i = 0; i < (int)max(number.size(), b.number.size()); ++i) {
                if (getDigit(i) - b.getDigit(i) - taken >= 0) {
                    ans.number.push_back(getDigit(i) - b.getDigit(i) - taken);
                    taken = 0;
                } else {
                    ans.number.push_back(getDigit(i) - b.getDigit(i) - taken + 10);
                    taken = 1;
                }
            }
            while (ans.number.size() > 1 && ans.number.back() == 0) {
                ans.number.pop_back();
            }
            if (ans.number.size() == 1 && ans.getDigit(0) == 0) {
                ans.negative = false;
            }
            return ans;
        }
        Integer ans;
        ans.negative = negative;
        int digit = 0;
        for (int i = 0; i < (int)max(number.size(), b.number.size()); ++i) {
            digit += getDigit(i) + b.getDigit(i);
            ans.number.push_back(digit % 10);
            digit /= 10;
        }
        if (digit > 0) {
            ans.number.push_back(digit);
        }
        if (ans.number.empty()) {
            ans.number = {0};
            ans.negative = false;
        }
        return ans;
    }
    Integer operator-(Integer b) const {
        return *this + (-b);
    }
    friend ostream &operator<<(ostream &out, const Integer &a);
};

ostream &operator<<(ostream &out, const Integer &a) {
    if (a.negative) {
        out << '-';
    }
    for (int i = (int)a.number.size() - 1; i >= 0; --i) {
        out << a.getDigit(i);
    }
    return out;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] != '9') {
        string s2 = "";
        for (int i = 0; i < n; ++i) {
            s2 += '9';
        }
        cout << (Integer(s2) - Integer(s)) << '\n';
    } else {
        string s2 = "";
        for (int i = 0; i < n + 1; ++i) {
            s2 += '1';
        }
        cout << (Integer(s2) - Integer(s)) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}