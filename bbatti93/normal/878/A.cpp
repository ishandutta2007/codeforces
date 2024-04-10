#include <bits/stdc++.h>

using namespace std;

int n, k;
int a=0, b=1023;
char c;
int x=0, y=0;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> c >> k;
        if(c=='|') {
            a=a|k;
            b=b|k;
        }
        if(c=='&') {
            a=a&k;
            b=b&k;
        }
        if(c=='^') {
            a=a^k;
            b=b^k;
        }
    }

    for(int i=1;i<1024;i*=2) {
        bool e=i&a, f=i&b;
        if(e&&f) {y+=i; }
        if(!e&&f) {x+=i; }
        if(e&&!f) {x+=i;y+=i; }
    }
    cout << 2 << endl << "& " << x << endl << "^ " << y << endl;
    return 0;
}