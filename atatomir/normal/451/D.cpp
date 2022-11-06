#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[100005];
long n,i,v,p;
int c[2][2];
long long e,o;

int main()
{
    scanf("%s",s);
    n = strlen(s);

    for(i=0;i<n;i++){
        v = s[i] - 'a'; p = (i+1)%2;
        c[v][p]++;
        e += c[v][p^1];
        o += c[v][p];
    }

    cout << e << ' ' << o;

    return 0;
}