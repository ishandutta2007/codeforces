#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
int a[15], sum;

int main() 
{
	int n;
	cin >> n;
	//cout << pow(2, 15) << endl << (-361) % 360;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 2; i++)
	{
		sum += a[0];
		for (int i1 = 0; i1 < 2; i1++)
		{
			sum += a[1];
			for (int i2 = 0; i2 < 2; i2++)
			{
				sum += a[2];
				for (int i3 = 0; i3 < 2; i3++)
				{
					sum += a[3];
					for (int i4 = 0; i4 < 2; i4++)
					{
						sum += a[4];
						for (int i5 = 0; i5 < 2; i5++)
						{
							sum += a[5];
							for (int i6 = 0; i6 < 2; i6++)
							{
								sum += a[6];
								for (int i7 = 0; i7 < 2; i7++)
								{
									sum += a[7];
									for (int i8 = 0; i8 < 2; i8++)
									{
										sum += a[8];
										for (int i9 = 0; i9 < 2; i9++)
										{
											sum += a[9];
											for (int i10 = 0; i10 < 2; i10++)
											{
												sum += a[10];
												for (int i11 = 0; i11 < 2; i11++)
												{
													sum += a[11];
													for (int i12 = 0; i12 < 2; i12++)
													{
														sum += a[12];
														for (int i13 = 0; i13 < 2; i13++)
														{
															sum += a[13];
															for (int i14 = 0; i14 < 2; i14++)
															{
																sum += a[14];
																if (sum % 360 == 0)
																{
																	cout << "YES";
																	return 0;
																}
																a[14] *= (-1);
																sum += a[14];
															}
															a[13] *= (-1);
															sum += a[13];
														}
														a[12] *= (-1);
														sum += a[12];
													}
													a[11] *= (-1);
													sum += a[11];
												}
												a[10] *= (-1);
												sum += a[10];
											}
											a[9] *= (-1);
											sum += a[9];
										}
										a[8] *= (-1);
										sum += a[8];
									}
									a[7] *= (-1);
									sum += a[7];
								}
								a[6] *= (-1);
								sum += a[6];
							}
							a[5] *= (-1);
							sum += a[5];
						}
						a[4] *= (-1);
						sum += a[4];
					}
					a[3] *= (-1);
					sum += a[3];
				}
				a[2] *= (-1);
				sum += a[2];
			}
			a[1] *= (-1);
			sum += a[1];
		}
		a[0] *= (-1);
		sum += a[0];
	}
	cout << "NO";
	return 0;
}