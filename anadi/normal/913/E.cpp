#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

string res[300][4];

struct cmp{
	bool operator() (const int &a, const int &b){
		if(res[a%256][a / 256].size() == res[b%256][b / 256].size())
			return res[a%256][a / 256] > res[b%256][b / 256];
		return res[a%256][a / 256].size() > res[b%256][b / 256].size();
	}
};

priority_queue <int, vector <int>, cmp> Q;

bool like(string &a, string &b){
	if(a.size() == 0)	return false;
	if(b.size() == 0)	return true;

	if(a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main(){
	res[240][0] = 'x';
	Q.push(240);
	
	res[204][0] = 'y';
	Q.push(204);
	
	res[170][0] = 'z';
	Q.push(170);
	
	while(!Q.empty()){
		int t1 = Q.top()%256, t2 = Q.top() / 256;
		Q.pop();
		
		string a = '(' + res[t1][t2] + ')';
		if(like(a, res[t1][0])){
			res[t1][0] = a;
			Q.push(t1);
		}
		
		if(t2 == 0){
			a = '!' + res[t1][t2];
			
			if(like(a, res[t1 ^ 255][1])){
				res[t1 ^ 255][1] = a;
				Q.push(256 + (t1 ^ 255));
			}
		}
		
		string b;
		if(t2 <= 2){
			for(int i = 0; i < 256; ++i)
				for(int j = 0; j <= 2; ++j)
					if(res[i][j].size() != 0){
						a = res[t1][t2] + '&' + res[i][j];
						b = res[i][j] + '&' + res[t1][t2];
						
						if(like(b, a))
							swap(b, a);

						int to = t1 & i;
						if(like(a, res[to][2])){
							res[to][2] = a;
							Q.push(2 * 256 + to);
						}
					}
		}

		for(int i = 0; i < 256; ++i)
			for(int j = 0; j <= 3; ++j)
				if(res[i][j].size() != 0){
					a = res[t1][t2] + '|' + res[i][j];
					b = res[i][j] + '|' + res[t1][t2];
					
					if(like(b, a))
						swap(b, a);

					int to = t1 | i;
					if(like(a, res[to][3])){
						res[to][3] = a;
						Q.push(3 * 256 + to);
					}
				}
	}
	
	int quest; scanf("%d", &quest);
	while(quest--){
		char s[N]; scanf("%s", s);
		int t = 0;
		for(int i = 7; i >= 0; --i)
			t *= 2, t += s[i] - '0';
		
		string a = res[t][0];
		for(int i = 1; i <= 3; ++i)
			if(like(res[t][i], a))
				a = res[t][i];
		
		for(char c: a)
			printf("%c", c);
		puts("");
	}

	return 0;
}