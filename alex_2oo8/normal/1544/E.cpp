#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;

char s[MX + 1];

int main() {
	int T;
	ignore = scanf("%d", &T);
	while (T--) {
		ignore = scanf("%s", s);
		
		int n = strlen(s);
		
		vector<int> cnt(256, 0);
		for (int i = 0; i < n; i++) cnt[s[i]]++;
		
		auto finish = [&](int start) {
			for (int i = 0, j = start; i < 256; i++) {
				for (int k = 0; k < cnt[i]; k++, j++) {
					s[j] = i;
				}
			}
		};
		
		{
			int c = -1;
			for (int i = 0; i < 256; i++)
				if (cnt[i] == 1) {
					c = i;
					break;
				}
			
			if (c != -1) {
				s[0] = c;
				cnt[c] = 0;
				
				finish(1);
				
				printf("%s\n", s);
				continue;
			}
		}
		
		vector<int> letters;
		for (int i = 0; i < 256; i++)
			if (cnt[i] != 0)
				letters.push_back(i);
		
		if (letters.size() == 1) {
			printf("%s\n", s);
			continue;
		}
		
		int a = letters[0];
		int b = letters[1];
		
		if (cnt[a] <= n - cnt[a] + 2) {
			s[0] = s[1] = a;
			cnt[a] -= 2;
			
			int k = 2;
			for (int i = a + 1; i < 256 && cnt[a] > 0; i++) {
				while (cnt[i] > 0 && cnt[a] > 0) {
					s[k++] = i;
					s[k++] = a;
					
					cnt[i]--;
					cnt[a]--;
				}
			}
			
			finish(k);
			
			printf("%s\n", s);
			continue;
		}
		
		if (letters.size() == 2) {
			s[0] = a;
			cnt[a]--;
			
			int k = 1;
			while (cnt[b] > 0) {
				s[k++] = b;
				cnt[b]--;
			}
			
			finish(k);
			
			printf("%s\n", s);
			continue;
		}
		
		int c = letters[2];
		
		s[0] = a;
		cnt[a]--;
		
		s[1] = b;
		cnt[b]--;
		
		int k = 2;
		while (cnt[a] > 0) {
			s[k++] = a;
			cnt[a]--;
		}
		
		s[k++] = c;
		cnt[c]--;
		
		finish(k);
		
		printf("%s\n", s);
	}
	
	return 0;
}