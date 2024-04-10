#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef long double ld;


string s1, s2;

int check(char ch1, char ch2){
    if (ch1 == 'R' && ch2 == 'S')
        return -1;
    if (ch1 == 'R' && ch2 == 'P')
        return 1;
    if (ch1 == 'R' && ch2 == 'R')
        return 0;
    
    if (ch1 == 'S' && ch2 == 'P')
        return -1;
    if (ch1 == 'S' && ch2 == 'R')
        return 1;
    if (ch1 == 'S' && ch2 == 'S')
        return 0;
    
    if (ch1 == 'P' && ch2 == 'R')
        return -1;
    if (ch1 == 'P' && ch2 == 'S')
        return 1;
    if (ch1 == 'P' && ch2 == 'P')
        return 0;

}


int main(){
    int i, l1, l2, n, kol1, kol2, ans1, ans2;
    scanf("%d", &n);
    cin >> s1;
    cin >> s2;
    l1 = s1.length();
    l2 = s2.length();
    kol1 = 0;
    kol2 = 0;
    forn(i, l1 * l2){
        if (check(s1[i % l1], s2[i % l2]) == 1)
            kol1++;
        if (check(s1[i % l1], s2[i % l2]) == -1)
            kol2++;
    }
    ans1 = kol1 * (n / (l1 * l2));
    ans2 = kol2 * (n / (l1 * l2));
    n = n % (l1 * l2);
    forn(i, n){
        if (check(s1[i % l1], s2[i % l2]) == 1)
            ans1++;
        if (check(s1[i % l1], s2[i % l2]) == -1)
            ans2++;
    }
    cout << ans1 << " " << ans2;
    return 0;

}