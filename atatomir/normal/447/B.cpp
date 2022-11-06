#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[1010];
long n,i,k;
long v['z'+10],maxim;
long long sum;

int main()
{
    scanf("%s",s);
    n = strlen(s);

    scanf("%ld\n",&k);
    for(i='a';i<='z';i++) {
        scanf("%ld ",&v[i]);
        if(v[i] > maxim) maxim = v[i];
    }

    for(i=0;i<n;i++){
        sum += 1LL*(i+1)*v[s[i]];
    }
    for(i=n+1;i<=n+k;i++) sum += 1LL*i*maxim;

    cout << sum;

    return 0;
}