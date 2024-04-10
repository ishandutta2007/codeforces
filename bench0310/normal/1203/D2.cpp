#include <bits/stdc++.h>

using namespace std;

vector<int> solve(string a,string b)
{
    vector<int> res(b.size());
    int idx=0;
    for(int i=0;i<(int)a.size();i++)
    {
        if(a[i]==b[idx]) res[idx++]=i;
        if(idx==(int)b.size()) break;
    }
    return res;
}

int main()
{
	string s,t;
	cin >> s >> t;
	int n=s.size();
	int m=t.size();
	vector<int> a=solve(s,t);
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	vector<int> b=solve(s,t);
	reverse(b.begin(),b.end());
	for(int &c:b) c=n-c-1;
	int res=max(b[0],n-a[m-1]-1);
	for(int i=0;i+1<m;i++) res=max(res,b[i+1]-a[i]-1);
	printf("%d\n",res);
	return 0;
}