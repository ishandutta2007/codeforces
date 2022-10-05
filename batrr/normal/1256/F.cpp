#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, cnt[N];
char s[N], t[N];
int main()
{
	int q;
	scanf("%d", &q);
	while(q--){
		scanf("%d", &n);
		scanf("%s", &s);
		scanf("%s", &t);      
		for(int i = 0; i < 26; i++)
			cnt[i] = 0;
		for(int i = 0; i < n; i++)
			cnt[s[i] - 'a']++;
		for(int i = 0; i < n; i++)
			cnt[t[i] - 'a']--;
		bool ok = 1;		
		for(int i = 0; i < 26; i++)
			if(cnt[i] != 0)
				ok = 0;
		if(!ok){
		    puts("NO");
			continue;
		}	
		bool kek = 0;
		for(int i = 0; i < 26; i++)
			cnt[i] = 0;
		for(int i = 0; i < n; i++)
			cnt[s[i] - 'a']++;
		for(int i = 0; i < 26; i++)
			if(cnt[i] > 1)
				kek = 1;
		if(kek){
			puts("YES");
			continue;
		}
		bool A = 1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j + 1 < n; j++){
				if(s[j] < s[j + 1]){
					A^=1;
					swap(s[j], s[j + 1]);
				}
				if(t[j] < t[j + 1]){
					A^=1;
					swap(t[j], t[j + 1]);
				}
			}
		}
		if(A)           
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}