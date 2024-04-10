fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }
    var m1 = -1
    var m2 = -1
    var m3 = -1
    var i1 = -1
    var i2 = -1
    var i3 = -1
    var i = 1
    
    for (c in a) {
        if(m1==-1){
            m1=c;
            i1=i;
        }
        else if(c!=m1){
            if(m2==-1)
            {
                m2=c;
                i2=i;
            }
            else if(c!=m2)
            {
                if(m3==-1)
                {
                    m3=c;
                    i3=i;
                }
            }
        }
        i=i+1
    }
    
    if(m3==-1)
    {
        println("-1\n-1\n-1");
    }
    else
    {
        if(m1<m2&&m1<m3)
        {
            println(i1)
            if(m2<m3)
            {
                println(i2)
                println(i3)
            }
            else
            {
                println(i3)
                println(i2)
            }
        }
        else if(m2<m1&&m2<m3)
        {
            println(i2)
            if(m1<m3)
            {
                println(i1)
                println(i3)
            }
            else
            {
                println(i3)
                println(i1)
            }
        }
        else
        {
            println(i3)
            if(m1<m2)
            {
                println(i1)
                println(i2)
            }
            else
            {
                println(i2)
                println(i1)
            }
        }
    }
}