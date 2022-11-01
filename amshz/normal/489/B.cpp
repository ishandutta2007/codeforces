# include<iostream>
# include<vector>
# include<string>

using namespace std;

const int N = 10e5+10;
int a[N];
int b[N];

int main(){
	int n ,m ,q;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	cin >> m;
	for (int i=0; i<m; i++){
		cin >> b[i];
	}
	//cout << "Yes";
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if (a[j] < a[i]){
				q = a[j];
				a[j] = a[i];
				a[i] = q;
			}
		}
	}
	for (int i=0; i<m; i++){
		for (int j=i+1; j<m; j++){
			if (b[j] < b[i]){
				q = b[j];
				b[j] = b[i];
				b[i] = q;
			}
		}
	}
	int t = 0;
	int str = 0;
	for (int i=0; i<n; i++){
		//cout << a[i];
		for (int j=str; j<m; j++){
			if (a[i] > b[j]){
				if (a[i]-b[j] <= 1){
					t += 1;
					str = j+1;
					break;
				}
			}
			else{
				if (b[j]-a[i] <= 1){
					t += 1;
					str = j+1;
					break;
				}
			}
		}
	}
	cout << t;
	return 0;
}