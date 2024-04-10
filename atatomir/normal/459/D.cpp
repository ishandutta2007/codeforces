#include <iostream>
#include <map>

using namespace std;

#define maxN 1000005

long n,i;
long a[maxN],l[maxN],r[maxN];
map<long,long> M;
long aib[maxN];
long long answer;


long zeros(long x){
    return (x ^ (x-1))&x;
}

void add(long pos,long x){
    while(pos <= n){
        aib[pos] += x;
        pos = pos + zeros(pos);
    }
}

long sum(long pos){
    long ans = 0;
    while(pos > 0){
        ans += aib[pos];
        pos = pos - zeros(pos);
    }
    return ans;
}

int main()
{
    cin >> n;
    for(i=1;i<=n;i++) {
        cin >> a[i];
        l[i] = ++M[a[i]];
    }
    M.clear();
    for(i=n;i;i--){
        r[i] = ++M[a[i]];
    }

    for(i=1;i<=n;i++) add(r[i],1);
    for(i=1;i<n;i++){
        add(r[i],-1);
        answer = answer + sum(l[i]-1);
    }

    cout << answer;

    return 0;
}