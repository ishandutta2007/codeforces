uses math;
var
  a,b:array[1..150000]of longint;
  n,k,q,kpot:longint;
  zn1,zn2:longint;
  i,j:longint;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[b[random(r-l)+l]];
         repeat
           while a[b[i]]<x do
            inc(i);
           while x<a[b[j]] do
            dec(j);
           if not(i>j) then
             begin
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
function search(key:longint):boolean;
  var
    i:longint;
  begin
    for i:=1 to kpot do
      if b[i]=key then exit(true);
    exit(false);
   end;
begin
  read(n,k,q);
  for i:=1 to n do
    read(a[i]);

  for i:=1 to q do
    begin
      read(zn1,zn2);
      if zn1=1 then
        begin
          if kpot<k then
            begin
              b[kpot+1]:=zn2;
              inc(kpot);
              sort(1,kpot);
            end
          else
            if a[zn2]>a[b[1]] then
              begin
                b[1]:=zn2;
                sort(1,k);
              end;
        end
      else
        if search(zn2) then writeln('YES')
        else writeln('NO');
    end;
end.