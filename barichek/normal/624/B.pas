var
  a:array[0..100000]of int64;
  n:longint;
  i,j:longint;
  ok:boolean;
procedure sort(l,r: longint);
      var
         i,j:longint;
         x,y:int64;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
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
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
begin
  read(n);
  for i:=1 to n do
    read(a[i]);

  sort(1,n);
  while not ok do
    begin
      ok:=true;
      for i:=1 to n-1 do
        if (a[i]=a[i+1]) and (a[i]<>0) then
          begin
            dec(a[i]);
            ok:=false;
            break;
          end;
    end;

  for i:=1 to n do
    inc(a[0],a[i]);

  writeln(a[0]);
end.