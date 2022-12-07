#include<bits/stdc++.h>
using namespace std;
int n,a[200003],l[200003],r[200003],ans,sum[200003];
bool imp[200003];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=n;i>0;i--)
		l[a[i]]=i;
	for(int i=1;i<=n;i++)
		r[a[i]]=i;
	vector<pair<int,int> >v;
	for(int i=1;i<=n;i++)
		if(l[i]!=r[i]){
			v.push_back(make_pair(l[i],r[i]));
			sum[r[i]]--;
			imp[l[i]]=1;
			imp[r[i]]=1;
			sum[l[i]+1]++;
		}
	sort(v.begin(),v.end());
	if(!v.size()){cout<<0;return 0;}
	vector<pair<int,int> >seg;seg.push_back(v[0]);
	for(int i=1;i<v.size();i++)
		if(v[i].second>seg.back().second)
			seg.push_back(v[i]);
		else
			imp[v[i].first]=0,imp[v[i].second]=0;
	v.clear();
	if(seg.size()>1){
		v.push_back(seg[0]);
		for(int i=1;i<seg.size()-1;i++)
			if(seg[i+1].first>v.back().second)
				v.push_back(seg[i]);
			else
				imp[seg[i].first]=0,imp[seg[i].second]=0;
		v.push_back(seg.back());
	}else v=seg;
//	for(int i=0;i<v.size();i++)
//		cout<<v[i].first<<' '<<v[i].second<<endl;
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
		if(sum[i]>0&&!imp[i])
			ans++;
	}
	for(int i=1;i<v.size();i++)
		if(v[i-1].second>v[i].first){
//			cout<<seg[i-1].first<<' '<<seg[i-1].second<<' '<<seg[i].first<<' '<<seg[i].second<<endl;
			ans++;
		}
	cout<<ans;
}