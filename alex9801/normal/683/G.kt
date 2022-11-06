import java.io.*;
import java.util.Scanner;

fun f(a: Int, b: Int): Int = if (a == 0) b else f(b%a, a)

fun main(args: Array<String>) {
	val input = Scanner(System.`in`)
	
	var s = input.next()
	var a = 0
	var b = 0
	var c = 0
	var u = 0
	var v = 0

	var p = 1
	var q = 1

	var n = 1
	var m = 1
	
	for(t in s)
	{
		var x = t.toInt()
		if(x == 46)
			u = 1
		else if(x == 40)
			v = 1
		else if(x == 41)
			v = 1
		else
		{
			x -= 48
			if(v == 1)
			{
				q *= 10
				c = 10*c + x
			}
			else if(u == 1)
			{
				p *= 10
				b = 10*b + x
			}
			else
				a = 10*a + x
		}
	}

	n = (q-1)*(a*p+b)+c
	m = p*(q-1)

	var g = f(n, m)

	n /= g
	m /= g

	print(n)
	print("/")
	print(m)
}