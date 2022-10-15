Program arsijo;
uses math;
Var a, n, i, e, d, l: longint;
        r: extended;
        ar: array [1..1002] of longint;

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
        Read(n, l);
        for i:=1 to n do
                Read(ar[i]);
        sort(1, n);
        e := ar[2] - ar[1];
        for i:=2 to (n-1) do
        begin
            d := ar[i+1] - ar[i];
            if d > e then
                e := d;
        end;
        if ((l - ar[n]) * 2 > e) or (ar[1] * 2 > e) then
        begin
            e := max(l - ar[n], ar[1]);
            WriteLn(e, '.00000000000');
        end else
            WriteLn(e / 2: 0: 10);
End.