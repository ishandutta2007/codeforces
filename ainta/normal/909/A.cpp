#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
char p[110], q[110];
string Res;
int main() {
	int i, j;
	scanf("%s%s", p, q);
	string aa = "";
	for (i = 0; p[i]; i++) {
		aa += p[i];
		string bb = "";
		for (j = 0; q[j]; j++) {
			bb += q[j];
			string s = aa + bb;
			if (!i && !j)Res = s;
			else if (s < Res)Res = s;
		}
	}
	printf("%s\n", Res.c_str());
}