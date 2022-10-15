Var a,b,c,s,x,k,t:int64;
    ans:array[1..100] of int64;
    i,j:longint;
Begin
    Readln(a,b,c);
    k:=0;
    For i:=1 to 81 do
    Begin
        s:=i;
        For j:=2 to a do s:=s*i;
        x:=b*s+c;
        t:=x;
        s:=0;
        While x<>0 do
        Begin
            inc(s,x mod 10);
            x:=x div 10;
        End;
        If (s=i) and (t < 1000000000) Then Begin inc(k); ans[k]:=t; End;
    End;
    Writeln(k);
    For i:=1 to k do Write(ans[i],' ');
End.