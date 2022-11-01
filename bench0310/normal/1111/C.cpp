#include <bits/stdc++.h>

using namespace std;

long long a,b;
multiset<int> s;

long long solve(long long l,long long r)
{
    long long num=distance(s.lower_bound(l),s.upper_bound(r));
    if(num==0) return a;
    if(l==r) return b*num;
    else return min((r-l+1)*b*num,solve(l,(l+r)/2)+solve((l+r)/2+1,r));
}

int main()
{
    long long n,k;
    cin >> n >> k >> a >> b;
    int temp;
    for(int i=0;i<k;i++)
    {
        cin >> temp;
        s.insert(temp);
    }
    cout << solve(1,1<<n) << endl;
    return 0;
}