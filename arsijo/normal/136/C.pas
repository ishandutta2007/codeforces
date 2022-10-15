Program arsijo;
Var i, n: longint;
        ar: array [1..100000] of longint;
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
        if ar[n] = 1 then
        begin
            for i:=1 to (n-1) do
                Write('1 ');
            Write(2);
        end else
        begin
            Write(1);
            for i:=1 to (n-1) do
                Write(' ', ar[i]);
        end;
End.