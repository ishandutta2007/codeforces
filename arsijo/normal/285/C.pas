Program arsijo;
Var n, i: longint;
        ans: int64;
        ar: array [1..300000] of longint;

procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=ar[l+random(r-l)];
         repeat
           while ar[i]<x do
            inc(i);
           while x<ar[j] do
            dec( j );
           if not(i>j) then
             begin
                y:=ar[i];
                ar[i]:=ar[j];
                ar[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

Begin

    Read(n);
    for i:=1 to n do
        Read(ar[i]);
    sort(1, n);
    ans := 0;
    for i:=1 to n do
        inc(ans, abs(ar[i] - i));
    WriteLn(ans);
End.