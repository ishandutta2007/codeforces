#include<bits/stdc++.h>
using namespace std;
multiset<int>s;
int a[600000],n;
multiset<int>::iterator it1,it2,it3;
int main(){
	//freopen("p.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		s.insert(a);
	}
	for(int i=1;i<=n;i++){
		int az=n-a[i],ans;
		s.insert(az);
		it1=s.lower_bound(az);
		if(--s.end()!=it1){it3=it1++;
		int ax=*it1;
		cout<<(a[i]+ax)%n<<' ';
		s.erase(it1);
		s.erase(it3);}else{
		it3=s.begin();
		cout<<(a[i]+*it3)%n<<' ';
		s.erase(it1);
		s.erase(it3);
		}
	}
	return 0;
}