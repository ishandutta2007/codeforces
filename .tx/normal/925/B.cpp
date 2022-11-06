#include <bits/stdc++.h>
          
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
pair<int, int> a[300007];

ll func[300007];
int ff = 0;

void solve(int s1, int s2){
	int uk = -1;
	for (int i = 0; i < n; i++){
		if (a[i].x * (ll)(i + 1) >= s1){
			uk = i;
			break;
		}
	}
	if (uk == -1) return;
	int uk2 = -1;
	for (int i = uk + 1; i < n; i++){
		if (a[i].x * (ll)(i - uk) >= s2){
			uk2 = i;
			break;
		}
	}
	if (uk2 == -1) return;
	if (ff == 0){
		cout << "Yes\n";
		cout << uk + 1 << ' ' << uk2 - uk << "\n";
		for (int i = 0; i <= uk; i++) cout << a[i].y + 1 << ' ';
		cout << "\n";
		for (int i = uk + 1; i <= uk2; i++) cout << a[i].y + 1 << ' ';
	} else {
		cout << "Yes\n";
		cout << uk2 - uk << ' ' << uk + 1 << "\n";
		for (int i = uk + 1; i <= uk2; i++) cout << a[i].y + 1 << ' ';
		cout << "\n";
		for (int i = 0; i <= uk; i++) cout << a[i].y + 1 << ' ';
	}
	exit(0);
}

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output2.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int s1, s2;
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; i++) cin >> a[i].x, a[i].y = i;
    sort(a, a + n);
	reverse(a, a + n);
	solve(s1, s2);
	ff = 1;
	solve(s2, s1);
	cout << "No";
}