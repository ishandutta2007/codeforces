#include <iostream>
#include <queue>

using namespace std;

long long n,m,k,p,x;
long l[1005],c[1005];
long long maxim;
long i,j;

priority_queue<long long> pql,pqc;
long long lines[1000005],columns[1000005];
long long result = - (1LL << 60);

int main()
{
    cin >> n >> m >> k >> p;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> x;
            l[i] += x; c[j] += x;
        }
    }

    for(i=1;i<=n;i++) pql.push(l[i]);
    for(i=1;i<=k;i++){
        x = pql.top(); pql.pop();
        lines[i] = lines[i-1] + x;
        pql.push(x-p*m);
    }

    for(i=1;i<=m;i++) pqc.push(c[i]);
    for(i=1;i<=k;i++){
        x = pqc.top(); pqc.pop();
        columns[i] = columns[i-1] + x;
        pqc.push(x-p*n);
    }

    for(i=0;i<=k;i++){
        j = k-i;
        result = max(result,lines[i]+columns[j]-1LL*i*j*p);
    }

    cout << result;

    return 0;
}