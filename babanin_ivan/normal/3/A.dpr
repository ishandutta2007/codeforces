program code1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
type check=record
      k:integer;
      s:string
     end;
var a:array[1..8,1..8]of check;
    c,c1:char;
    x,y,nx,ny,kx,ky,i,j:integer;
    b:array[1..80]of string;

procedure go(x,y:integer);
begin
 if(x=1)and(y=1)then begin
  if a[x+1,y+1].k>a[x,y].k+1 then begin
  a[x+1,y+1].k:=a[x,y].k+1;
  a[x+1,y+1].s:='RU';
  go(x+1,y+1)
 end;
  if a[x,y+1].k>a[x,y].k+1 then begin
  a[x,y+1].k:=a[x,y].k+1;
  a[x,y+1].s:='U';
  go(x,y+1)
 end;
  if a[x+1,y].k>a[x,y].k+1 then begin
  a[x+1,y].k:=a[x,y].k+1;
  a[x+1,y].s:='R';
  go(x+1,y);
 end;
  exit
 end;
 if(x=8)and(y=1)then begin
  if a[x-1,y+1].k>a[x,y].k+1 then begin
  a[x-1,y+1].k:=a[x,y].k+1;
  a[x-1,y+1].s:='LU';
  go(x-1,y+1)
 end;
  if a[x,y+1].k>a[x,y].k+1 then begin
  a[x,y+1].k:=a[x,y].k+1;
  a[x,y+1].s:='U';
  go(x,y+1)
 end;
  if a[x-1,y].k>a[x,y].k+1 then begin
  a[x-1,y].k:=a[x,y].k+1;
  a[x-1,y].s:='L';
  go(x-1,y)
 end;
  exit
 end;
 if(x=8)and(y=8)then begin
  if a[x-1,y-1].k>a[x,y].k+1 then begin
  a[x-1,y-1].k:=a[x,y].k+1;
  a[x-1,y-1].s:='LD';
  go(x-1,y-1)
 end;
  if a[x-1,y].k>a[x,y].k+1 then begin
  a[x-1,y].k:=a[x,y].k+1;
  a[x-1,y].s:='L';
  go(x-1,y)
 end;
  if a[x,y-1].k>a[x,y].k+1 then begin
  a[x,y-1].k:=a[x,y].k+1;
  a[x,y-1].s:='D';
  go(x,y-1)
 end;
  exit
 end;
 if(x=1)and(y=8)then begin
  if a[x+1,y-1].k>a[x,y].k+1 then begin
  a[x+1,y-1].k:=a[x,y].k+1;
  a[x+1,y-1].s:='RD';
  go(x+1,y-1)
 end;
  if a[x+1,y].k>a[x,y].k+1 then begin
  a[x+1,y].k:=a[x,y].k+1;
  a[x+1,y].s:='R';
  go(x+1,y);
 end;
  if a[x,y-1].k>a[x,y].k+1 then begin
  a[x,y-1].k:=a[x,y].k+1;
  a[x,y-1].s:='D';
  go(x,y-1)
 end;
  exit
 end;
 if x=1 then begin
  if a[x+1,y].k>a[x,y].k+1 then begin
  a[x+1,y].k:=a[x,y].k+1;
  a[x+1,y].s:='R';
  go(x+1,y);
 end;
  if a[x,y+1].k>a[x,y].k+1 then begin
  a[x,y+1].k:=a[x,y].k+1;
  a[x,y+1].s:='U';
  go(x,y+1)
 end;
  if a[x,y-1].k>a[x,y].k+1 then begin
  a[x,y-1].k:=a[x,y].k+1;
  a[x,y-1].s:='D';
  go(x,y-1)
 end;
  if a[x+1,y+1].k>a[x,y].k+1 then begin
  a[x+1,y+1].k:=a[x,y].k+1;
  a[x+1,y+1].s:='RU';
  go(x+1,y+1)
 end;
  if a[x+1,y-1].k>a[x,y].k+1 then begin
  a[x+1,y-1].k:=a[x,y].k+1;
  a[x+1,y-1].s:='RD';
  go(x+1,y-1)
 end;
  exit
 end;
 if x=8 then begin
  if a[x-1,y].k>a[x,y].k+1 then begin
  a[x-1,y].k:=a[x,y].k+1;
  a[x-1,y].s:='L';
  go(x-1,y)
 end;
  if a[x,y+1].k>a[x,y].k+1 then begin
  a[x,y+1].k:=a[x,y].k+1;
  a[x,y+1].s:='U';
  go(x,y+1)
 end;
  if a[x,y-1].k>a[x,y].k+1 then begin
  a[x,y-1].k:=a[x,y].k+1;
  a[x,y-1].s:='D';
  go(x,y-1)
 end;
  if a[x-1,y+1].k>a[x,y].k+1 then begin
  a[x-1,y+1].k:=a[x,y].k+1;
  a[x-1,y+1].s:='LU';
  go(x-1,y+1)
 end;
  if a[x-1,y-1].k>a[x,y].k+1 then begin
  a[x-1,y-1].k:=a[x,y].k+1;
  a[x-1,y-1].s:='LD';
  go(x-1,y-1)
 end;
  exit
 end;
 if y=1 then begin
  if a[x,y+1].k>a[x,y].k+1 then begin
  a[x,y+1].k:=a[x,y].k+1;
  a[x,y+1].s:='U';
  go(x,y+1)
 end;
  if a[x-1,y].k>a[x,y].k+1 then begin
  a[x-1,y].k:=a[x,y].k+1;
  a[x-1,y].s:='L';
  go(x-1,y)
 end;
  if a[x+1,y].k>a[x,y].k+1 then begin
  a[x+1,y].k:=a[x,y].k+1;
  a[x+1,y].s:='R';
  go(x+1,y);
 end;
  if a[x-1,y+1].k>a[x,y].k+1 then begin
  a[x-1,y+1].k:=a[x,y].k+1;
  a[x-1,y+1].s:='LU';
  go(x-1,y+1)
 end;
  if a[x+1,y+1].k>a[x,y].k+1 then begin
  a[x+1,y+1].k:=a[x,y].k+1;
  a[x+1,y+1].s:='RU';
  go(x+1,y+1)
 end;
  exit
 end;
 if y=8 then begin
  if a[x,y-1].k>a[x,y].k+1 then begin
  a[x,y-1].k:=a[x,y].k+1;
  a[x,y-1].s:='D';
  go(x,y-1)
 end;
  if a[x-1,y].k>a[x,y].k+1 then begin
  a[x-1,y].k:=a[x,y].k+1;
  a[x-1,y].s:='L';
  go(x-1,y)
 end;
  if a[x+1,y].k>a[x,y].k+1 then begin
  a[x+1,y].k:=a[x,y].k+1;
  a[x+1,y].s:='R';
  go(x+1,y);
 end;
  if a[x-1,y-1].k>a[x,y].k+1 then begin
  a[x-1,y-1].k:=a[x,y].k+1;
  a[x-1,y-1].s:='LD';
  go(x-1,y-1)
 end;
  if a[x+1,y-1].k>a[x,y].k+1 then begin
  a[x+1,y-1].k:=a[x,y].k+1;
  a[x+1,y-1].s:='RD';
  go(x+1,y-1)
 end;
  exit
 end;
 if a[x,y+1].k>a[x,y].k+1 then begin
  a[x,y+1].k:=a[x,y].k+1;
  a[x,y+1].s:='U';
  go(x,y+1)
 end;
 if a[x,y-1].k>a[x,y].k+1 then begin
  a[x,y-1].k:=a[x,y].k+1;
  a[x,y-1].s:='D';
  go(x,y-1)
 end;
 if a[x-1,y].k>a[x,y].k+1 then begin
  a[x-1,y].k:=a[x,y].k+1;
  a[x-1,y].s:='L';
  go(x-1,y)
 end;
 if a[x+1,y].k>a[x,y].k+1 then begin
  a[x+1,y].k:=a[x,y].k+1;
  a[x+1,y].s:='R';
  go(x+1,y);
 end;
 if a[x-1,y+1].k>a[x,y].k+1 then begin
  a[x-1,y+1].k:=a[x,y].k+1;
  a[x-1,y+1].s:='LU';
  go(x-1,y+1)
 end;
 if a[x-1,y-1].k>a[x,y].k+1 then begin
  a[x-1,y-1].k:=a[x,y].k+1;
  a[x-1,y-1].s:='LD';
  go(x-1,y-1)
 end;
 if a[x+1,y+1].k>a[x,y].k+1 then begin
  a[x+1,y+1].k:=a[x,y].k+1;
  a[x+1,y+1].s:='RU';
  go(x+1,y+1)
 end;
 if a[x+1,y-1].k>a[x,y].k+1 then begin
  a[x+1,y-1].k:=a[x,y].k+1;
  a[x+1,y-1].s:='RD';
  go(x+1,y-1)
 end
end;

{procedure ru;
begin
 if a[x+1,y+1].k>a[x,y].k+1 then begin
  a[x+1,y+1].k:=a[x,y].k+1;
  a[x+1,y+1].s:='RU';
  go(x+1,y+1)
 end;
end;
procedure u;
begin
 if a[x,y+1].k>a[x,y].k+1 then begin
  a[x,y+1].k:=a[x,y].k+1;
  a[x,y+1].s:='U';
  go(x,y+1)
 end;
end;
procedure r;
begin
 if a[x+1,y].k>a[x,y].k+1 then begin
  a[x+1,y].k:=a[x,y].k+1;
  a[x+1,y].s:='R';
  go(x+1,y);
 end
end;
procedure lu;
begin
 if a[x-1,y+1].k>a[x,y].k+1 then begin
  a[x-1,y+1].k:=a[x,y].k+1;
  a[x-1,y+1].s:='LU';
  go(x-1,y+1)
 end;
end;
procedure l;
begin
 if a[x-1,y].k>a[x,y].k+1 then begin
  a[x-1,y].k:=a[x,y].k+1;
  a[x-1,y].s:='L';
  go(x-1,y)
 end;
end;
procedure ld;
begin
 if a[x-1,y-1].k>a[x,y].k+1 then begin
  a[x-1,y-1].k:=a[x,y].k+1;
  a[x-1,y-1].s:='LD';
  go(x-1,y-1)
 end;
end;
procedure d;
begin
 if a[x,y-1].k>a[x,y].k+1 then begin
  a[x,y-1].k:=a[x,y].k+1;
  a[x,y-1].s:='D';
  go(x,y-1)
 end;
end;
procedure rd;
begin
 if a[x+1,y-1].k>a[x,y].k+1 then begin
  a[x+1,y-1].k:=a[x,y].k+1;
  a[x+1,y-1].s:='RD';
  go(x+1,y-1)
 end;
end;}

begin
 {reset(input,'input.txt');
 rewrite(output,'output.txt');   }
 readln(c,c1);
 nx:=ord(c)-ord('a')+1;
 ny:=ord(c1)-ord('0');
 read(c,c1);
 kx:=ord(c)-ord('a')+1;
 ky:=ord(c1)-ord('0');
 if (nx=kx)and(ny=ky)then begin
  writeln(0);
  halt(0);
 end;
 for i:=1 to 8 do
  for j:=1 to 8 do a[i,j].k:=maxint;
 a[nx,ny].k:=0;
 go(nx,ny);
 writeln(a[kx,ky].k);
 x:=kx;
 y:=ky;
 i:=1;
 while not((x=nx)and(y=ny))do begin
  b[i]:=a[x,y].s;
  inc(i);
  if a[x,y].s='R'then dec(x)
  else
  if a[x,y].s='L'then inc(x)
  else
  if a[x,y].s='U'then dec(y)
  else
  if a[x,y].s='D'then inc(y)
  else
  if a[x,y].s='RU'then begin
   dec(x);
   dec(y)
  end
  else
  if a[x,y].s='RD'then begin
   dec(x);
   inc(y)
  end
  else
  if a[x,y].s='LD'then begin
   inc(x);
   inc(y)
  end
  else
  if a[x,y].s='LU'then begin
   inc(x);
   dec(y)
  end
 end;
 for i:=a[kx,ky].k downto 1 do
  writeln(b[i]);
end.