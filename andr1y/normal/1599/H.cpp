//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 1e5+18;
ll _x0, _y0, _x1, _y1;

ll ask(ll x, ll y){
	cout<<"? "<<x<<' '<<y<<endl;
	ll r;cin>>r;
	/*if(x>=_x0 && x<=_x1){
		if(y<_y0) r=_y0 - y;
		else r=y-_y1;
	}else if(y>=_y0 && y<=_y1){
		if(x<_x0) r=_x0-x;
		else r=x-_x1;
	}else r = min({abs(_x0-x)+abs(_y0-y), abs(_x1-x)+abs(_y0-y), abs(_x0-x)+abs(_y1-y), abs(_x1-x)+abs(_y1-y)});
	cout <<"DEBUG "<<r<<endl;*/
	return r;
}

/*

	. 1 . . 2
	. . 1 2 .
	* . 2 1 *

*/


pll intersect_bottom(ll d1, ll d2){
	// x+y = d1
	// x-y = d2
	// x = d1-y
	// d1-2y = d2
	// d1-d2 = 2y
	// y = (d1-d2)/2
	ll y = (d1-d2)/2;
	if(y<1) y=1;
	ll x = d1-y;
	return {x, y};
}

/*

	* 1 2 . *
	. 2 1 . .
	2 . . 1 .

*/

pll intersect_top(ll d1, ll d2){
	// x+y = d1
	// x-y = d2
	// x = d1-y
	// d1-2y = d2
	// d1-d2 = 2y
	// y = (d1-d2)/2
	ll y = (d1-d2+1)/2;
	if(y>1e9) y=1e9;
	ll x = d1-y;
	return {x, y};
}

/*

	* 1 . . 2
	. . 1 2 .
	* . 2 1 .

*/

pll intersect_left(ll d1, ll d2){
	// x+y = d1
	// x-y = d2
	// y = d1-x
	// 2x-d1 = d2
	// d2-d1 = 2x
	// x = (d2-d1)/2
	ll x = (d2+d1)/2;
	if(x<1) x=1;
	ll y = d1-x;
	return {x, y};
}

/*

	. 1 2 . *
	. 2 1 . .
	2 . . 1 *

*/

pll intersect_right(ll d1, ll d2){
	// x+y = d1
	// x-y = d2
	// y = d1-x
	// 2x-d1 = d2
	// d2+d1 = 2x
	// x = (d2+d1)/2
	ll x = (d2+d1+1)/2;
	if(x>1e9) x=1e9;
	ll y = d1-x;
	return {x, y};
}


signed main(){
	/* 
	
	1 . . . 2
	. . . . .
	0 . . . 3

	*/
	//cin >> _x0 >> _y0 >> _x1 >> _y1;
	ll v0 = ask(1,1)+2;
	ll v1 = ask(1,1e9)-999999999;
	ll v2 = 2e9-ask(1e9,1e9);
	ll v3 = 999999999-ask(1e9,1);
	pll il = intersect_left(v0, v1);
	pll ir = intersect_right(v2, v3);
	pll it = intersect_top(v2, v1);
	pll ib = intersect_bottom(v0, v3);
	ll fl = ask(il.x, il.y)+il.x;
	ll fb = ask(ib.x, ib.y)+ib.y;
	ll ft = (it.y-ask(it.x, it.y));
	ll fr = (ir.x-ask(ir.x, ir.y));
	cout<<"! "<<fl<<' '<<fb<<' '<<fr<<' '<<ft<<endl;
}