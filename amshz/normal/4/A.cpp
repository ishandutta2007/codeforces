# include <iostream>
# include <vector>

using namespace std;
int main(){
	int a;
	cin >> a;
	if (a%2 == 0 and a != 2){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}