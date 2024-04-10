#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n,x,y,bin[10],w[1005];
vector<int> a,b;

int ask(vector<int> a)
{
	if (a.empty()) return 0;
	printf("? %d ",a.size());
	for (vector<int>::iterator it=a.begin();it!=a.end();it++) printf("%d ",*it);
	puts("");
	int ans;
	cin>>ans;
	return ans;
}

/*int ask(vector<int> a) {
    if (a.empty()) {
        return 0;
    }
    cout << "? ";
    cout << a.size() << " ";
    for (vector<int>::iterator it=a.begin();it!=a.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}*/

int solve(vector<int> a)
{
	int w1=0;
	for (vector<int>::iterator it=a.begin();it!=a.end();it++) w[++w1]=*it;
	int l=1,r=w1;
	while (l<=r)
	{
		int mid=(l+r)/2;
		a.clear();
		for (int i=l;i<=mid;i++) a.push_back(w[i]);
		int tmp=ask(a);
		if (tmp==y||tmp==(x^y)) r=mid-1;
		else l=mid+1;
	}
	return w[r+1];
}

/*int solve(vector<int> a) {
    int left = 0;
    int right = (int) a.size();
    
    while (right - left > 1) {
        int mid = (left + right) / 2;
        
        vector<int> b;
        for (int i = left; i < mid; i++) {
            b.push_back(a[i]);
        }
        
        int cur = ask(b);
        if (cur == y || cur == (x ^ y)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    return a[left];
}*/

int main()
{
	scanf("%d%d%d",&n,&x,&y);
	bin[0]=1;
	for (int i=1;i<=9;i++) bin[i]=bin[i-1]*2;
	int diff=0,diff_bit=-1;
	for (int i=0;i<=9;i++)
	{
		a.clear();
		for (int j=1;j<=n;j++)
			if ((j&bin[i])) a.push_back(j);
		int tmp=ask(a);
		if (tmp==y||tmp==(x^y)) diff|=bin[i],diff_bit=i;
	}
	a.clear();
	for (int i=1;i<=n;i++)
		if ((i&bin[diff_bit])) a.push_back(i);
		else b.push_back(i);
	int pos1,pos2;
	if (a.size()>b.size()) pos1=solve(b);
	else pos1=solve(a);
	pos2=pos1^diff;
	if (pos1>pos2) swap(pos1,pos2);
	printf("! %d %d\n",pos1,pos2);
	return 0;
}