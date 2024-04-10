Program arsijo;
Var i, n, c, j: longint;
        d, f, e, sum, avg, r: int64;
        a, b: array [1..1000000] of longint;
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
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
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
        Read(n, r, avg);
        for i:=1 to n do
                Read(b[i], a[i]);
        sum := 0;
        for i:=1 to n do
        begin
            inc(sum, b[i]);
        end;
        sort(1, n);
        e := 0;
       // for i:=1 to n do Writeln(b[i], ' ', a[i]);
        j := 0;
        d := (n * avg) - sum;
        while d > 0 do
        begin
                //WriteLn('!');
            inc(j);
           // WriteLn(r - b[j]);
            f := r - b[j];
            if d <= f then
            begin
                inc(e, (d * a[j]));
                WriteLn(e);
                exit;
            end;
            inc(sum, f);
            inc(e, (f * a[j]));
            dec(d, f);
            {while b[j] < r do
            begin
                inc(e, a[j]);
              //  WriteLn(a[j]);
                inc(sum);
                inc(b[j]);
               // WriteLn(sum, ' i = ', j);
               // WriteLn(sum div n);

                if (sum >= (n * avg)) then
                begin
                    WriteLn(e);
                    exit;
                end;
            end;     }
        end;
        WriteLn(e);
End.