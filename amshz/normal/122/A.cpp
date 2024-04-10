# include<iostream>
# include<vector>
# include<string>

using namespace std;

int f1(int n){
	if ((n == 4) or (n == 7)){
		return 2;
	}
	if ((n%10 != 4) and (n%10 != 7)){
		return 1;
	}
	//cout << n-n%10;
	return f1((n-n%10)/10);
}

int main(){
	int n;
	cin >> n;
	if (f1(n) == 2){
		cout << "YES";
		return 0;
	}
	for (int i=1; i<=n; i++){
		if (n%i == 0 and f1(i) == 2){
			//cout << i;
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}