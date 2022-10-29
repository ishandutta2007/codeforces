#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string in[100005],arr[100005];
pair<pair<int,char>,int> p[100005];
bool vowel(char c)
{
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
pair<int,char> get(string s)
{
	pair<int,int> a(0,0);
	for (char i:s)
	{
		if (vowel(i))
		{
			a.first++;
			a.second=i;
		}
	}
	return a;
}
int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> in[i];
		p[i]={get(in[i]),i};
	}
	sort(p,p+n);
	for (int i=0;i<n;i++)
	arr[i]=in[p[i].second];
	vector<vector<string> > ans;
	vector<string> tmp;
	for (int i=0;i<n;i++)
	{
		if (i!=n-1 && get(arr[i])==get(arr[i+1]))
		{
			vector<string> v(4);
			v[1]=arr[i];
			v[3]=arr[i+1];
			ans.push_back(v);
			i++;
		}
		else
		tmp.push_back(arr[i]);
	}
	int cur=0;
	for (int i=0;i<ans.size();i++)
	{
		while (cur<(int)tmp.size()-1 && get(tmp[cur]).first!=get(tmp[cur+1]).first)
		cur++;
		if (cur>=(int)tmp.size()-1)
		{
			while (ans.size()>i+1)
			{
				ans[i][0]=ans.back()[1];
				ans[i][2]=ans.back()[3];
				ans.pop_back();
				i++;
			}
			if (ans.size()==i+1)
			ans.pop_back();
			break;
		}
		ans[i][0]=tmp[cur];
		ans[i][2]=tmp[cur+1];
		cur+=2;
	}
	cout << ans.size() << endl;
	for (auto v:ans)
	cout << v[0] << ' ' << v[1] << endl << v[2] << ' ' << v[3] << endl;
}