#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ull unsigned long long
#define pr 31

bool hash_comp(pair < ull, int > a, pair < ull, int > b)
{
	if(a.first < b.first)
		return true;
	return false;
}

int main()
{
	char S[51];
	int S2[51];
	cin >> S;
	int len = strlen(S);
	
	int max_count = 1;
	int max_len = 1;
	vector < int > ans;
	bool any = 0;
	for(int i=0;i<len;i++)
	{	
		if((S[i]-'0')==7||(S[i]-'0')==4)
		{
			any = true;
		
		
			if(ans.size()==0)
				ans.push_back(i);
		}
	}
	if(!any)
	{
		cout << -1;
		return 0;
	}
	
	
	
	

	
	vector < pair <ull,int> > hash;

	

	for(int i=1;i<=len;i++)
	{	
		ull H = 0;
		bool good;
		hash.clear();
		for(int j=0;j<=len-i;j++)
		{
			good = 1;
			H = 0;
			for(int k=0;k<i;k++)
			{
				H = H*pr + (S[j+k]-'0');
				if((S[j+k]-'0')!=4&&(S[j+k]-'0')!=7)
					good = 0;
			}
			if(good)
			{
				hash.push_back(pair < ull,int >(H,j));
			}
		}
		sort(hash.begin(),hash.begin()+hash.size());
		int group_len = 1;
		int l=1;
		do
		{
			if(l>=hash.size())
				break;
			while(l<hash.size()&&hash[l].first==hash[l-1].first)
			{
				l++;
				group_len++;
			}
			if(group_len==max_count)
			{
				ans.push_back(hash[l-1].second);
			}
			if(group_len>max_count)
			{
				ans.clear();
				ans.push_back(hash[l-1].second);
				max_count = group_len;
				max_len = i;
			}
			l++;
			group_len = 1;
		}while(l<hash.size());
	}

	int min_str = ans[0];

	for(int i=1;i<ans.size();i++)
	{
		if(lexicographical_compare(&S[ans[i]],&S[ans[i]+max_len],&S[min_str],&S[min_str+max_len]))
			min_str = ans[i];
	}



	for(int i=0;i<max_len;i++)
	{
		cout << S[min_str+i];
	}

	cout << '\n';

	
	
	return 0;
}