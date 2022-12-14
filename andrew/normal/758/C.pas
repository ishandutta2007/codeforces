var
  n,m,k,x,y,w,max,min:int64;
  a:array[0..100,0..100] of int64;
  i,j:integer;

begin
  read(n,m,k,x,y);
  for i:=1 to n do
    for j:=1 to m do
      begin
        inc(a[i,j]);
        inc(w);
      end;
  for i:=n-1 downto 2 do
    for j:=1 to m do
      begin
        inc(a[i,j]);
        inc(w);
      end;
  for i:=1 to n do
    for j:=1 to m do
      a[i,j]:=a[i,j]*(k div w);
  k:=k mod w;
  for i:=1 to n do
    for j:=1 to m do
      if k > 0 then
        begin
          inc(a[i,j]);
          dec(k);
        end;
  for i:=n-1 downto 2 do
    for j:=1 to m do
      if k > 0 then
        begin
          inc(a[i,j]);
          dec(k);
        end;
  max:=a[1,1]; min:=a[1,1];
  for i:=1 to n do
    for j:=1 to m do
      begin
        if a[i,j]>max then max:=a[i,j];
        if a[i,j]<min then min:=a[i,j];
      end;
  writeln(max,' ',min,' ',a[x,y]);
end.