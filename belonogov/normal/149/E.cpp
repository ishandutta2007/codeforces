#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
const int maxn = 2e5;

string s, s1, s2, s3;

int pref[maxn], suf[maxn], z[maxn], p[maxn];

void genpref(int m){
    int n, i, j, d;
    n = s2.length();
    memset(p, 0, sizeof p);
    for (i = 1; i < n; i++){
        j = p[i - 1];
        while (j > 0 && s2[i] != s2[j])
            j = p[j - 1];
        if (s2[i] == s2[j])
            j++;
        p[i] = j;
    }
    d = 0;
    for (i = m; i < n; i++){
        d = max(p[i], d);
        pref[i - m] = d;
    }
}

void gensuf(int m){
    int n, i, j, d;
    n = s3.length();
    memset(p, 0, sizeof p);
    for (i = 1; i < n; i++){
        j = p[i - 1];
        while (j > 0 && s3[i] != s3[j])
            j = p[j - 1];
        if (s3[i] == s3[j])
            j++;
        p[i] = j;
    }
    d = 0;
    for (i = m; i < n; i++){
        d = max(p[i], d);
        suf[n - i - 1] = d;
    }
}







string r (string s){
    int n = s.length(), i;
    for (i = 0; i < n / 2; i++)
        swap(s[n - i - 1], s[i]);
    return s;
}


int main(){
   int cnt = 0, i, t, n, m, j;
    bool check;
    cin >> s;
    n = s.length();
    cin >> t;
    for (i = 0; i < t; i++){
        cin >> s1;
        m = s1.length();
        if (m == 1)
            continue;
        s2 = s1 + "#" + s;
        genpref(m + 1);
        s3 = r(s1) + "#" + r(s);
        gensuf(m + 1);
        if (suf[0] == m || pref[n - 1] == m){
            cnt++;
            continue;
        }
        check = false;
        for (j = 0; j < n - 1 && ! check; j++)
            if (pref[j] + suf[j + 1] >= m){
                cnt++;
                check = true;
            }
    }




    cout << cnt;
}