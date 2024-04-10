var
 l1,l2,k0,k1,k2,l,j,s,o,len,r:longint;
 d:char;
 a:array[1..100000] of longint;
 i,n:longint;
 f,p:boolean;
procedure viv(i1,j1:longint);
var
 i,j:longint;
begin


end;
begin
 f:=true;
 i:=0;
 k1:=0;
 k2:=0;
 k0:=0;
  while f do
   begin
    inc(i);
    read(d);
    p:=false;
     case d of
      '1':begin p:=true; a[i]:=1; end;
      '2':begin a[i]:=2; p:=true; end;
      '3':begin a[i]:=3; p:=true; end;
      '4':begin a[i]:=4; p:=true; end;
      '5':begin a[i]:=5; p:=true; end;
      '6':begin a[i]:=6; p:=true; end;
      '7':begin a[i]:=7; p:=true; end;
      '8':begin a[i]:=8; p:=true; end;
      '9':begin a[i]:=9; p:=true; end;
      '0':begin a[i]:=0; p:=true; end;
      end;
      f:=p;
       if a[i] mod 3=0 then inc(k0) else
       if a[i] mod 3=1 then inc(k1) else
       inc(k2);
   end;
  n:=i-1;
  dec(k0);
  if n=1 then begin if a[1] mod 3<>0 then writeln(-1) else writeln(a[1]); exit; end;
 l:=(k1+2*k2) mod 3;
 if a[1] mod 3=0 then dec(k0) else
 if a[1] mod 3=1 then dec(k1) else
 dec(k2);
  if l=0 then begin for i:=1 to n do write(a[i]); exit; end;
  if l=1 then
          begin
           if k1>0 then
                    begin
                     for i:=2 to n do
                      if a[i] mod 3=1 then j:=i;
                     for i:=1 to n do
                      if i<>j then write(a[i]);
                      exit;
                    end;
           if (a[2]<>0) and (a[1] mod 3=l) then begin for i:=2 to n do write(a[i]); exit; end;
           if a[1] mod 3=0 then inc(k0) else
           if a[1] mod 3=1 then inc(k1) else
           inc(k2);
           if k2>1 then
                    begin
                    s:=2;
                     for i:=n downto 1 do
                      if (a[i] mod 3=2) then begin if s=2 then begin dec(s); j:=i end else if s=1 then begin dec(s); o:=i; end; end;
                      if n=2 then begin writeln(-1); exit; end;
                      r:=0;
                     for i:=1 to n do
                      if (i<>j) and (i<>o) and (a[i]<>0) then inc(r);
                      if r=0 then begin writeln(0); exit; end;
                       r:=0;
                       for i:=1 to n do
                      if (i<>j) and (i<>o) then if (r=1) then write(a[i]) else if (r=0) then if (a[i]<>0) then begin write(a[i]); r:=1; end;
                      exit;
                    end;
           if k1>0 then
                    begin
                     for i:=1 to n do
                      if a[i] mod 3=1 then j:=i;
                      r:=0;
                     for i:=1 to n do
                      if (i<>j) and (a[i]<>0) then inc(r);
                      if r=0 then begin writeln(0); exit; end;
                      r:=0;
                      for i:=1 to n do
                       if (i<>j) then if (r=1) then write(a[i]) else if (r=0) then if (a[i]<>0) then begin write(a[i]); r:=1; end;
                       //if (i<>j) and (a[i]<>0) then write(a[i]);
                      exit;
                    end;

          end;

          if l=2 then
          begin
           if k2>0 then
                    begin
                     for i:=2 to n do
                      if a[i] mod 3=2 then j:=i;
                     for i:=1 to n do
                      if i<>j then write(a[i]);
                      exit;
                    end;
           if (a[2]<>0) and (a[1] mod 3=l) then begin for i:=2 to n do write(a[i]); exit; end;
           if a[1] mod 3=0 then inc(k0) else
           if a[1] mod 3=1 then inc(k1) else
           inc(k2);
           if k1>1 then
                    begin
                    s:=2;
                     for i:=n downto 1 do
                      if (a[i] mod 3=1) then begin if s=2 then begin dec(s); j:=i end else if s=1 then begin dec(s); o:=i; end; end;
                      if n=2 then begin writeln(-1); exit; end;
                     r:=0;
                     for i:=1 to n do
                      if (i<>j) and (i<>o) and (a[i]<>0) then inc(r);
                      if r=0 then begin writeln(0); exit; end;
                       r:=0;
                       for i:=1 to n do
                      if (i<>j) and (i<>o) then if (r=1) then write(a[i]) else if (r=0) then if (a[i]<>0) then begin write(a[i]); r:=1; end;
                      //if (i<>j) and (i<>o) and (a[i]<>0) then write(a[i]);
                      exit;
                    end;
           if k2>0 then
           
                    begin
                    
                     for i:=1 to n do
                     
                      if a[i] mod 3=2 then j:=i;
                      
                      r:=0;
                     for i:=1 to n do
                      if (i<>j) and (a[i]<>0) then inc(r);
                     if r=0 then begin writeln(0); exit; end;
                     r:=0;
                     for i:=1 to n do
                      if (i<>j) then if (r=1) then write(a[i]) else if (r=0) then if (a[i]<>0) then begin write(a[i]); r:=1; end;
                      //if (i<>j) and (a[i]<>0) then write(a[i]);
                      exit;
                    end;

          end;

   writeln(-1);
end.