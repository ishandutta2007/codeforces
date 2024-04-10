#include <bits/stdc++.h>
using namespace std;

int to_int(string s) {
    int res = 0;
    while(!s.empty()) {
        res = res * 10 + (s[0] - '0');
        s.erase(0, 1);
    }
    return res;
}

int main()
{
    string s, t;
    cin >> s;
    while(s.back() != 'e')
        t += s.back(), s.pop_back();
    s.pop_back();
    reverse(t.begin(), t.end());
    int b = to_int(t), np = s.find('.'), fr = s.length() - np - 1;
    if(fr <= b) {
        s.erase(s.find('.'), 1);
        for(int i = b - fr; i; i--)
            s += '0';
    } else {
        s.insert(s.find('.') + b + 1, ".");
        s.erase(s.find('.'), 1);
    }
    if(s.back() == '0' && s[s.length()-2] == '.')
       s.pop_back(), s.pop_back();
    cout << s;
    return 0;
}