fun main()
{
    val(a,b,c)=readLine()!!.split(' ').map(String::toInt)
    print(3*minOf(a+1,b,c-1))
}