		#include<cstdio>


		#include<cstring>

		#include<cmath>



		#include<cstdlib>


		#include<iostream>



		#include<algorithm>



		#include<string>


	#include<vector>


			#include<queue>



	#include<set>



			#include<map>


	using namespace std;

		#define ll long long


			ll n   ,  k;



	ll phi  (   ll x )

			{

		ll p=2  , tmp=x;

	while   (   x>1  )

		{

	if ( p*p>x   )    return tmp/x*   ( x-1  ) ;



	if  ( x%p == 0  )

		{

		tmp=tmp/p*  ( p-1   )   ;

			x  /=  p;while   (  x%p  ==  0 )   x /= p;


	  }



			p ++  ;


		 }


	return tmp;

			  }


		int main   ( )

			{


		scanf   (  "%I64d%I64d"  ,   &n , &k  )  ;


		if  (  k%2 ==  0  )   k  --   ;


		while (   k>0   )

		{



		n=phi (   n )  ;k -=  2;

			if (  n  ==   1  )   break;

			  }

	printf (  "%I64d"   , n%1000000007  )   ;


		   }