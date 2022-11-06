import java.io.*;
import java.util.Scanner;

fun f(n: Int, m: Int, p: Int): String
{
	for(j in 1..n)
	{
		for(k in 1..m)
		{
			if(j*k == p)
			{
				return "Yes"
			}
		}
	}
	return "No"
}

fun main(args: Array<String>) {
	val input = Scanner(System.`in`)

	val (q) = readLine()!!.split(' ').map(String::toInt)
	
	for(i in 1..q)
	{
		val (n, m, p) = readLine()!!.split(' ').map(String::toInt)

		println(f(n, m, p))
	}
}