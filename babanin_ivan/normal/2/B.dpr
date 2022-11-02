program code2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type rou=record
      k:integer;
      s:string
     end;
var a,b:array[1..1000,1..1000]of rou;
    c,d:array[1..1000,1..1000]of integer;
    fx,fy,i,j,n,e:integer;
    s:string;
    f:boolean;

procedure goa(x,y:integer);
begin
 for y:=1 to n do
  for x:=1 to n do begin
  if (x<n)and(d[x+1,y]>b[x+1,y].k+d[x,y])then begin
   d[x+1,y]:=b[x+1,y].k+d[x,y];
   b[x+1,y].s:='R'
  end;
  if (y<n)and(d[x,y+1]>b[x,y+1].k+d[x,y])then begin
   d[x,y+1]:=b[x,y+1].k+d[x,y];
   b[x,y+1].s:='D'
  end
 end
end;

procedure gob(x,y:integer);
begin
 for y:=1 to n do
  for x:=1 to n do begin
   if (x<n)and(c[x+1,y]>a[x+1,y].k+c[x,y])then begin
    c[x+1,y]:=a[x+1,y].k+c[x,y];
    a[x+1,y].s:='R'
   end;
   if (y<n)and(c[x,y+1]>a[x,y+1].k+c[x,y])then begin
    c[x,y+1]:=a[x,y+1].k+c[x,y];
    a[x,y+1].s:='D'
   end
  end
end;

begin
 {reset(input,'input.txt');
 rewrite(output,'output.txt');   }
 readln(n);
 for j:=1 to n do begin
  for i:=1 to n do read(a[i,j].k);
  readln
 end;
 f:=false;
 for j:=1 to n do
  for i:=1 to n do
   if a[i,j].k=0 then begin
    f:=true;
    fx:=i;
    fy:=j
   end;
 for j:=1 to n do
  for i:=1 to n do
   if a[i,j].k<>0 then begin
    b[i,j].k:=0;
    e:=a[i,j].k;
    a[i,j].k:=0;
    while e mod 5=0 do begin
     e:=e div 5;
     inc(b[i,j].k)
    end;
    while e mod 2=0 do begin
     e:=e div 2;
     inc(a[i,j].k)
    end
   end
   else begin
         a[i,j].k:=1;
         b[i,j].k:=1
        end;
 for i:=1 to n do
  for j:=1 to n do begin
                    c[i,j]:=maxint;
                    d[i,j]:=maxint
                   end;
 c[1,1]:=a[1,1].k;
 d[1,1]:=b[1,1].k;
 goa(1,1);
 gob(1,1);
 if f and (c[n,n]>=1)and(d[n,n]>=1)then begin
  writeln(1);
  for i:=1 to fx-1 do write('R');
  for j:=1 to n-1 do write('D');
  for i:=fx+1 to n do write('R');
  halt(0)
 end;
 if c[n,n]<d[n,n]then begin
  writeln(c[n,n]);
  i:=n;
  j:=n;
  e:=0;
  s:='';
  while not((i=1)and(j=1))do begin
   s:=s+a[i,j].s;
   if a[i,j].s='R'then dec(i)
    else dec(j)
  end;
  for i:=length(s) downto 1 do write(s[i]);
 end
 else begin
       writeln(d[n,n]);
       i:=n;
       j:=n;
       e:=0;
       s:='';
       while not((i=1)and(j=1))do begin
        s:=s+b[i,j].s;
        if b[i,j].s='R'then dec(i)
         else dec(j)
       end;
       for i:=length(s) downto 1 do write(s[i]);
      end
end.