#pragma warning(disable:4996)
#include<stdio.h>
struct trie{
	trie *ch[26];
	int D1, D2;
	bool ter;
	trie(){
		for (int i = 0; i < 26; i++)ch[i] = NULL;
		ter = false;
		D1 = D2 = 0;
	}
	void ins(char *key){
		if (!*key){
			ter = true;
			return;
		}
		if (!ch[*key - 'a'])ch[*key - 'a'] = new trie();
		ch[*key - 'a']->ins(key + 1);
	}
	void DP(){
		int w[26] = { 0 }, i, c = 0;
		for (i = 0; i < 26; i++){
			if (ch[i]){
				ch[i]->DP();
				w[ch[i]->D1] |= 1;
				w[ch[i]->D2] |= 2;
				c++;
			}
		}
		if (!c){
			D1 = 0;
			D2 = 1;
			return;
		}
		for (i = 0; i < 26; i++)if (!(w[i] & 1))break;
		D1 = i;
		for (i = 0; i < 26; i++)if (!(w[i] & 2))break;
		D2 = i;
	}
};
char p[100010];
int main()
{
	trie *root;
	int i, n, k;
	scanf("%d%d", &n, &k);
	root = new trie();
	for (i = 0; i < n; i++){
		scanf("%s", p);
		root->ins(p);
	}
	root->DP();
	if (root->D1 && root->D2){
		printf("First\n");
	}
	else if (root->D1){
		if (k % 2 == 1)printf("First\n");
		else printf("Second\n");
	}
	else{
		printf("Second\n");
	}
}