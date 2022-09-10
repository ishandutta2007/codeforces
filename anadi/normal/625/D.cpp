#include <bits/stdc++.h>

using namespace std;

int n;
string s;
string Left, Right;

void go(int from, int to, int c1, int c2){
	if(from > to && c1 == c2){
		if(Left[0] == '0')
			return;

		reverse(Right.begin(), Right.end());
		cout << Left + Right << endl;
		exit(0);
	}

	if(from == to){
		int cur = s[from] - '0';
		cur += 10 * c1 - c2;
		
		if(cur & 1)
			return;
		
		Left.push_back(cur / 2 + '0');
		go(from + 1, to - 1, 0, 0);
	}
	
	int Right_val = s[to] - '0' - c2;	
	int Left_val = s[from] - '0' + 10 * c1;

//	cout << from << " " << to << " " << c1 << " " << c2 << "\n";
//	cout << Left_val << " " << Right_val << "\n";
	if(Left_val == Right_val){
		Left.push_back(Left_val + '0');
		Right.push_back('0');
		return go(from + 1, to - 1, 0, 0);
	}
	
	if(Left_val - 1 == Right_val && Right_val >= 0){
		Left.push_back(Right_val + '0');
		Right.push_back('0');
		return go(from + 1, to - 1, 1, 0);
	}
	
	if(Left_val == Right_val + 10 && Right_val < 9){
		Left.push_back('9');
		Right.push_back('0' + Left_val - 9);
		return go(from + 1, to - 1, 0, 1);
	}
	
	if(Left_val == Right_val + 11){
		Left.push_back('9');
		Right.push_back('0' + Right_val + 1);
		return go(from + 1, to - 1, 1, 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);

	cin >> s;
	n = s.size();
	
	go(0, n - 1, 0, 0);
	Left.clear(), Right.clear();

	if(s[0] == '1' && n > 1)
		go(1, n - 1, 1, 0);
		
	cout << "0" << endl;
	return 0;
}