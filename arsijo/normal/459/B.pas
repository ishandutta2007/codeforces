Program arsijo;
Var i, j, n: longint;
        max, min, e, c, d: int64;
        ar: array [1..200000] of int64;

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
    min := ar[1];
    max := ar[n];
    e := 1;
    d := 1;
    for i:=2 to n do
        if ar[i] = min then
                inc(e) else
                break;
    if e = n then
    begin
        WriteLn(0, ' ', (e * (e-1) div 2));
        exit;
    end;
    for i:=(n-1) downto 1 do
        if ar[i] = max then
                inc(d) else
                break;
    WriteLn(max-min, ' ', e*d);
End.