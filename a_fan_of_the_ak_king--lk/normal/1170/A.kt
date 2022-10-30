import java.util.*

fun main(args:Array<String>)
{
    val sc = Scanner(System.`in`)
    var t=sc.nextInt()
    for(i in 1..t)
    {
        var a=sc.nextInt()
        var b=sc.nextInt()
        if(a<b)
        {
            print(1);
            print(' ');
            print(a-1);
            print(' ');
            print(b-a+1);
            print('\n');
        }
        else
        {
            print(1);
            print(' ');
            print(b-1);
            print(' ');
            print(a-b+1);
            print('\n');
        }
    }
}