import java.lang.AssertionError
import java.util.Scanner
private fun readLn()=readLine()!!
private fun readInt()=readLn().toInt()
private fun readLong()=readLn().toLong()
private fun readDouble()=readLn().toDouble()
private fun readStrings()=readLn().split(" ")
private fun readInts()=readStrings().map{it.toInt()}
private fun readLongs()=readStrings().map{it.toLong()}
private fun readDoubles()=readStrings().map{it.toDouble()}
fun main(){
//    val reader=Scanner(System.`in`)
    var T=1
    while(T>0){
        T=T-1
        var n=readInt()
        var a=readLn().toString()
        var b=readLn().toString()
        var c=ArrayList<Int>()
        var ap=ArrayList<Char>()
        var bp=ArrayList<Char>()
        for(i in 0 until n){
            ap.add(a[i])
            bp.add(b[i])
        }
        for(i_Fake in 0 until n){
            var i=n-i_Fake-1
            var flag=1
            if(i==0){

            }else if(((bp[i-1].toLong()+ap[i-1].toLong())%2==1.toLong())){
                var aa=0.toLong()
                aa=aa+ap[i].toLong()
                aa=aa+bp[i].toLong()
                aa=aa-194.toLong()
                var ss=(i-1).toInt()
                if(aa<26.toLong()){
                    aa=aa+26.toLong()
                    bp[ss]=bp[ss]-1
                }
                else{
                    aa=aa-26.toLong()
                    bp[ss]=bp[ss]+1
                }
                c.add(('a'.toLong()+(aa/2.toLong())).toInt())
                flag=0
            }
            if(flag==1){
                var aa=0.toLong()
                aa=aa+ap[i].toLong()
                aa=aa+bp[i].toLong()
                c.add(((aa/2.toLong())).toInt())
            }
        }
        for(i_Fake in 0 until n){
            var i=n-i_Fake-1
            print(c[i].toChar())
        }
        print('\n')
    }
}