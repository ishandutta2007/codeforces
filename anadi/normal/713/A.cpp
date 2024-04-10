#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PDD pair <D, D>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

void WriteInt(int a){
	printf("%d\n", a);
	fflush(stdout);
}

void WriteDouble(double a){
	printf("%.6lf\n", a);
	fflush(stdout);
}

void WriteString(string a){
	cout << a << "\n";
	cout.flush();
}

int quest;
map <string, int> M;
int t[20];

void rozloz(LL a, int add){
	int i = 0;
	while(a > 0){
		t[++i] = a%2;
		a /= 10LL;
	}
	
	bool take = false;
	string s;
	for(i; i >= 1; --i){
		if(t[i] == 1)
			take = true;
		if(take)
			s.push_back(t[i] + '0');
	}
	
	if(s.size() == 0)
		s = '0';
	while(s.size() <= 18){
		M[s] += add;
		s = '0' + s;
	}
}

int main(){
	scanf("%d", &quest);
	while(quest--){
		char s[2];
		scanf("%s", s);
		if(s[0] == '+'){
			LL a;
			scanf("%I64d", &a);
			rozloz(a, 1);
		}
		
		if(s[0] == '-'){
			LL a;
			scanf("%I64d", &a);
			rozloz(a, -1);
		}
		
		if(s[0] == '?'){
			string s;
			cin >> s;
			printf("%d\n", M[s]);
		}
	}
	
	return 0;
}