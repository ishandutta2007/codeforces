Program arsijo;
Var i, n, k: longint;
        ar: array [1..12] of longint;

procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=ar[l+random(r-l)];
         repeat
           while ar[i]>x do
            inc(i);
           while x>ar[j] do
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
    Read(k);
    for i := 1 to 12 do
        Read(ar[i]);
    sort(1, 12);
    n := 0;
    for i:=1 to 12 do
    begin
        if n >= k then
        begin
            WriteLn(i-1);
            exit;
        end;
        inc(n, ar[i]);
    end;
    if n >= k then
        WriteLn(12) else
        WriteLn(-1);

End.