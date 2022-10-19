#include <bits/stdc++.h>
using namespace std;

#ifdef L
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#define M (int(1e9)+7)

#define Smax 505
char inp[Smax];
int ss[Smax];
int x;
int s;
int t;

int solve()
{
	int l = 0, len = s, read = 0, sum = s;
	deque<int> back;

	while(l != x) {
		++l;
		if(read == s) {
			read = back.front();
			back.pop_front();
		}
		int times = ss[read];

		// debug("[%d %d]", l, read);
		// debug("<");
		// for(int i : back) debug("%d ", i);
		// debug(">\n");

		assert(1 <= times && times <= 3);
		assert(read < s);

		int blen = back.size();
		len = (len + (((len - l + M) % M) * (times - 1)) % M) % M;
		for(int i = 0; i < times - 1 && sum <= x; ++i) {
			if(read != s - 1) {
			back.push_back(read+1);
			sum += s - read - 1;
			}
			for(int j = 0; j < blen; ++j) {
				back.push_back(back[j]);
				sum += s - back[j];
			}
		}

		++read;
	}

	return len;
}

int main()
{
	scanf("%d", &t);
	for(int i = 0; i < t; ++i) {
		scanf("%d", &x);
		scanf(" %s", inp);
		s = 0;
		while(inp[s]) {
			ss[s] = inp[s] - '0';
			++s;
		}
		printf("%d\n", solve());
	}

}