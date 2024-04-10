uses math;
var
  a:array[1..100000]of longint;
  n,m:longint;
  ans:longint;
  s,dop:ansistring;
  i,j:longint;
  zn:longint;
function search(key:longint):boolean;
  var
    low,high,mid:longint;
  begin
    low:=1; high:=n;
    while (low<=high) do
      begin
        mid:=(low+high) div 2;
        if key<a[mid] then high:=mid-1
        else if key>a[mid] then low:=mid+1
        else exit(true);
      end;
    exit(false);
   end;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[random(r-l)+l];
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
  read(n,m);
  for i:=1 to n do
    begin
      read(a[i]);
    end;

  sort(1,n);
  i:=1;
  while (m>0) and (i<=m) do
    begin
      if not search(i) then
        begin
          dec(m,i);
          if m<0 then break;
          inc(ans);
          str(i,dop);
          if s='' then s:=dop
          else s:=s+' '+dop;
        end;
      inc(i);
    end;
  writeln(ans);
  writeln(s);
end.