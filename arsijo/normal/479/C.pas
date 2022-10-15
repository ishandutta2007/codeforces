Program arsijo;
Var n, i, j: longint;
        ans, y: int64;
        a, b: array [1..5000] of int64;
           {
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[l+random(r-l)];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec( j );
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                y := b[i];
                b[i] := b[j];
                b[j] := y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end; }

Begin
        Read(n);
        for i:=1 to n do
                Read(a[i], b[i]);
        //sort(1, n);
        for i:=1 to n-1 do
                for j:=i+1 to n do
                        if (a[i] > a[j]) or ( (a[i] = a[j]) and (b[i] > b[j]) ) then
                        begin
                            y:=a[i];
                            a[i]:=a[j];
                            a[j]:=y;
                            y := b[i];
                            b[i] := b[j];
                            b[j] := y;
                        end;
        ans := 0;
        for i:=1 to n do
                if (b[i] >= ans) then ans := b[i] else
                        ans := a[i];
        WriteLn(ans);
End.