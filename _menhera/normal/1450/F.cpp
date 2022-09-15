#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int N; scanf("%d", &N);
		vector<int> arr;
		int ps = 0;
		vector<int> spe;
		auto makecnt = [&](vector<int> arr)
		{
			vector<int> ret(N+1);
			for(auto x: arr) ret[x]++;
			return ret;
		};
		for(int i=0; i<N; ++i)
		{
			int t; scanf("%d", &t);
			arr.push_back(t);
			if(i != 0 && arr[i] == arr[i-1])
			{
				spe.push_back(arr[ps]); spe.push_back(arr[i-1]);
				ps = i;
			}
		}
		spe.push_back(arr[ps]); spe.push_back(arr[N-1]);
		auto arrcnt = makecnt(arr); int maxarr = *max_element(arrcnt.begin(), arrcnt.end());
		auto specnt = makecnt(spe); int maxspe = *max_element(specnt.begin(), specnt.end());
		// check zero
		int ans = (int)spe.size()/2-1;
		if(maxarr > (N+1)/2) ans = -1;
		else
		{
			//cout << spe.size() << " " << maxspe << endl;
			int rem = maxspe - ((int)spe.size()-maxspe);
			ans += max(0, (rem-2)/2);
		}
		printf("%d\n", ans);
	}
}