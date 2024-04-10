#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int up[N], dwn[N], rght[N], lft[N];
int sup[N], sdwn[N], srght[N], slft[N];
int pup[N], pdwn[N], prght[N], plft[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n = s.size();
		for(int i = 0; i <= n; i++)
			up[i] = dwn[i] = rght[i] = lft[i] = sup[i] = sdwn[i] = srght[i] = slft[i] = 0;
		int mxu = 0, mxd = 0, mxr = 0, mxl = 0;
		int curu = 0, curr = 0;
		for(int i = 0; i < s.size(); i++)
		{	
			if(s[i] == 'W')
				curu++;
			else if(s[i] == 'S')
				curu--;
			else if(s[i] == 'A')
				curr--;
			else
				curr++;
			mxu = max(mxu, curu);
			mxd = max(mxd, -curu);
			mxr = max(mxr, curr);
			mxl = max(mxl, -curr);
			up[i] = curu;
			dwn[i]= -curu;
			rght[i] = curr;
			lft[i] = -curr;
 		}
		pup[0] = up[0];
		pdwn[0] = dwn[0];
		prght[0] = rght[0];
		plft[0] = lft[0];
		sup[n - 1] = up[n - 1];
		sdwn[n - 1] = dwn[n - 1];
		srght[n - 1] = rght[n - 1];
		slft[n - 1] = lft[n - 1];
 		for(int i = 1; i < s.size(); i++)
 		{
 			pup[i] = max(pup[i - 1], up[i]);
 			pdwn[i] = max(pdwn[i - 1], dwn[i]);
 			plft[i] = max(plft[i - 1], lft[i]);
 			prght[i] = max(prght[i - 1], rght[i]);
 		}
 		for(int i = n - 2; i >= 0; i--)
 		{
 			sup[i] = max(sup[i + 1], up[i]);
 			slft[i] = max(slft[i + 1], lft[i]);
 			srght[i] = max(srght[i + 1], rght[i]);
 			sdwn[i] = max(sdwn[i + 1], dwn[i]);
 		}
		int ans = (1 + mxr + mxl) * (1 + mxu + mxd);
		for(int i = 0; i < s.size(); i++)
		{
			//Add down
			{
				int curUp = max(sup[i] - 1, 0LL);
				if(i >= 1)
				{
					curUp = max(curUp, pup[i - 1]);
					curUp = max(curUp, up[i - 1] - 1);
				}
				int curDown = max(sdwn[i] + 1, 0LL);
				if(i >= 1)
				{
					curDown = max(curDown, pdwn[i - 1]);
					curDown = max(curDown, dwn[i - 1] + 1);
				}
				else
					curDown = max(curDown, 1LL);
				int curRight = max(srght[i], 0LL);
				if(i >= 1)
				{
					curRight = max(curRight, prght[i - 1]);
					curRight = max(curRight, rght[i - 1]);
				}
				int curLeft = max(slft[i], 0LL);
				if(i >= 1)
				{
					curLeft = max(curLeft, plft[i - 1]);
					curLeft = max(curLeft, lft[i - 1]);
				} 
				int cur = (1 + curUp + curDown) * (1 + curLeft + curRight);
				ans = min(ans, cur);
			}
			//Add up
			{
				int curUp = max(sup[i] + 1, 0LL);
				if(i >= 1)
				{
					curUp = max(curUp, pup[i - 1]);
					curUp = max(curUp, up[i - 1] + 1);
				}
				else
					curUp = max(curUp, 1LL);
				int curDown = max(sdwn[i] - 1, 0LL);
				if(i >= 1)
				{
					curDown = max(curDown, pdwn[i - 1]);
					curDown = max(curDown, dwn[i - 1] - 1);
				}
				int curRight = max(srght[i], 0LL);
				if(i >= 1)
				{
					curRight = max(curRight, prght[i - 1]);
					curRight = max(curRight, rght[i - 1]);
				}
				int curLeft = max(slft[i], 0LL);
				if(i >= 1)
				{
					curLeft = max(curLeft, plft[i - 1]);
					curLeft = max(curLeft, lft[i - 1]);
				}
				int cur = (1 + curUp + curDown) * (1 + curLeft + curRight);
				ans = min(ans, cur);
			}
			//Add rght
			{
				int curUp = max(sup[i], 0LL);
				if(i >= 1)
				{
					curUp = max(curUp, pup[i - 1]);
					curUp = max(curUp, up[i - 1]);
				}
				int curDown = max(sdwn[i], 0LL);
				if(i >= 1)
				{
					curDown = max(curDown, pdwn[i - 1]);
					curDown = max(curDown, dwn[i - 1]);
				}
				int curRight = max(srght[i] + 1, 0LL);
				if(i >= 1)
				{
					curRight = max(curRight, prght[i - 1]);
					curRight = max(curRight, rght[i - 1] + 1);
				}
				else
					curRight = max(curRight, 1LL);
				int curLeft = max(slft[i] - 1, 0LL);
				if(i >= 1)
				{
					curLeft = max(curLeft, plft[i - 1]);
					curLeft = max(curLeft, lft[i - 1] - 1);
				}
				int cur = (1 + curUp + curDown) * (1 + curLeft + curRight);
				ans = min(ans, cur);
			}
			//Add left
			{
				int curUp = max(sup[i], 0LL);
				if(i >= 1)
				{
					curUp = max(curUp, pup[i - 1]);
					curUp = max(curUp, up[i - 1]);
				}
				int curDown = max(sdwn[i], 0LL);
				if(i >= 1)
				{
					curDown = max(curDown, pdwn[i - 1]);
					curDown = max(curDown, dwn[i - 1]);
				}
				int curRight = max(srght[i] - 1, 0LL);
				if(i >= 1)
				{
					curRight = max(curRight, prght[i - 1]);
					curRight = max(curRight, rght[i - 1] - 1);
				}
				int curLeft = max(slft[i] + 1, 0LL);
				if(i >= 1)
				{
					curLeft = max(curLeft, plft[i - 1]);
					curLeft = max(curLeft, lft[i - 1] + 1);
				}
				else
					curLeft = max(curLeft, 1LL);
				int cur = (1 + curUp + curDown) * (1 + curLeft + curRight);
				ans = min(ans, cur);
			}
		}
		cout << ans << endl;
	}
	return 0;
}