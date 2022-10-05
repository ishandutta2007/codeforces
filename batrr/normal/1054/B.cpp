#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int n, x, mx;
int main(){
    scanf("%d", &n);;
    for(int i = 0; i < n; i++){
    	scanf("%d", &x);
    	if(x > mx){
    		printf("%d", i + 1);
    		return 0;
    	}
    	if(x == mx)
    		mx++;
    }
    printf("-1");
	return 0;
}