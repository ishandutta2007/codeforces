#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

int main()
{
    const long long inf=1000000000000000000;
	long long n,m,k;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	vector<long long> a(n+1,0);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	vector<long long> d(n+1,0);
	for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	vector<long long> v(n+1,-inf);
	for(int o=1;o<=n;o++) for(int i=0;i<m&&o+i<=n;i++) v[o]=max(v[o],d[o+i]);
	map<long long,int> s[m];
    for(long long o=1;o<=m;o++)
    {
        int id=(o%m);
        for(long long i=0;o+i*m<=n;i++)
        {
            long long val=v[o+i*m]-(i+1)*k;
            if(s[id].find(val)!=s[id].end()) s[id][val]++;
            else s[id].insert(make_pair(val,1));
        }
    }
    /*for(int o=0;o<m;o++)
    {
        cout << "id: " << o << endl;
        for(pair<long long,int> p:s[o]) cout << p.first << " " << p.second << endl;
    }*/
    long long res=0;
    for(long long i=1;i<=n;i++)
    {
        //cout << "in " << i << endl;
        int id=(i%m);
        res=max(res,(*s[id].rbegin()).first-d[i-1]+((i-1)/m)*k);
        long long val=v[i]-((i-1)/m+1)*k;
        //cout << "deleting " << val << endl;
        s[id][val]--;
        if(s[id][val]==0) s[id].erase(val);
    }
    printf("%I64d\n",res);
	return 0;
}