Program arsijo;
Var n, i, sum: longint;
        ar: array [1..1000] of int64;

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
        sum := 0;
        for i:=2 to n do

                if (ar[i] = ar[i-1]) and (ar[i] <> 0) then
                begin
                    if (i > 2) and (ar[i] = ar[i-2]) then
                    begin
                        WriteLn(-1);
                        exit;
                    end else
                        inc(sum);
                end;
        WriteLn(sum);


End.