#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int N; scanf("%d", &N);
		char buf[(int)4e5]; scanf("%s", buf);

		vector<bool> evenb(N), oddb(N);
		for(int i=0; i<N; ++i)
			if((buf[i] == 'L') ^ (i%2 == 0)) evenb[i] = true;
			else oddb[i] = true;
		
		vector<int> ev(N+1, 1), ov(N+1, 1);

		for(int i=0; i<N; ++i)
		{
			if(evenb[i]) ev[i+1] = ev[i]+1;
			if(oddb[i]) ov[i+1] = ov[i]+1;
		}
		for(int i=N-1; i>=0; --i)
		{
			if(evenb[i]) ev[i] = ev[i+1];
			if(oddb[i]) ov[i] = ov[i+1];
		}

		for(int i=0; i<=N; ++i) printf("%d ", (i%2 == 0)?ev[i]:ov[i]);
		puts("");
	}
}