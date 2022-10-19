///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("abm,bmi,bmi2")

const int N = 50, M = 20;

/*
 * guess you're ready 'cause i'm waiting for you
 * it's gonna be so exciting
 * got this feeling really deep in my soul
 * let's get out, i wanna go, come along, get it on
 *
 * gonna take my car, gonna sit in
 * gonna drive along 'til i get you
 * 'cause i'm crazy, hot and ready, but you like it
 * i wanna race for you (shall i go now?)
 *
 * GAS GAS GAS
 * i'm gonna step on the gas
 * tonight, i'll fly (and be your lover)
 * yeah, yeah, yeah
 * i'll be so quick as a flash
 * and i'll be your hero
 *
 * GAS GAS GAS
 * i'm gonna run as a flash
 * tonight, i'll fight (to be the winner)
 * yeah, yeah, yeah
 * i'm gonna step on the gas
 * and you'll see the big show
 */
double gasgasgas[1<<M];

int dif[N];
ll ok[1<<M];
string s[N];
int n, m;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop (i,0,n)
		cin >> s[i];
	m = s[0].size();
	double fans = 0;
	Loop (_,0,n) {
		swap(s[_], s[0]);
		Loop (i,1,n) {
			dif[i] = 0;
			Loop (j,0,m)
				dif[i] ^= (s[i][j] != s[0][j]) << j;
		}
		ok[0] = 0;
		Loop (i,0,m) {
			ok[1<<i] = 0;
			Loop (j,1,n)
				ok[1<<i] ^= ll(dif[j] >> i & 1) << j;
		}
		Loop (msk,1,1<<m) {
			int x = msk & -msk;
			if (x == msk)
				continue;
			ok[msk] = ok[msk ^ x] | ok[x];
		}
		Loop (msk,0,1<<m) {
			gasgasgas[msk] = 0;
			if (ok[(1<<m)-1-msk] == (1ll<<n)-2)
				continue;
			int cnt = 0;
			int msk2 = msk;
			while (msk2) {
				int x = msk2 & -msk2;
				msk2 ^= x;
				++cnt;
				gasgasgas[msk] += gasgasgas[msk ^ x]+1;
			}
			gasgasgas[msk] /= cnt;
			//cout << msk << "M\n";
			//cout << gasgasgas[msk] << "!\n";
		}
		fans += gasgasgas[(1<<m)-1];
	}
	fans /= n;
	cout << fixed << setprecision(9) << fans << '\n';
}